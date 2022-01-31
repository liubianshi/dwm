/* See LICENSE file for copyright and license details. */

/* appearance */
static const unsigned int borderpx  = 2;        /* border pixel of windows */
static const unsigned int gappx     = 18;       /* gap pixel between windows */
static const unsigned int snap      = 32;       /* snap pixel */
static const int swallowfloating    = 0;        /* 1 means swallow floating windows by default */
static const unsigned int gappih    = 10;       /* horiz inner gap between windows */
static const unsigned int gappiv    = 10;       /* vert inner gap between windows */
static const unsigned int gappoh    = 10;       /* horiz outer gap between windows and screen edge */
static const unsigned int gappov    = 10;       /* vert outer gap between windows and screen edge */
static       int smartgaps          = 0;        /* 1 means no outer gap when there is only one window */
static const unsigned int systraypinning = 0;   /* 0: sloppy systray follows selected monitor, >0: pin systray to monitor X */
static const unsigned int systrayonleft = 0;   	/* 0: systray in the right corner, >0: systray on left of status text */
static const unsigned int systrayspacing = 2;   /* systray spacing */
static const int systraypinningfailfirst = 1;   /* 1: if pinning fails, display systray on the first monitor, False: display systray on the last monitor*/
static const int showsystray        = 1;     /* 0 means no systray */
static const int showbar            = 1;     /* 0 means no bar */
static const int topbar             = 1;     /* 0 means bottom bar */
static const Bool viewontag         = True;     /* Switch view on tag switch */

static const char *fonts[]          = { 
    "FiraCode Nerd Font Mono:pixelsize=24:antialias=true:autohint:false:hint:ture:hintstyle:hintslight",
    "WenQuanYi Micro Hei Mono:pixelsize=24:antialias=true:autohint:false:hint:ture:hintstyle:hintslight",
    "Noto Color Emoji:pixelsize=24:antialias=true:autohint:false:hint:ture:hintstyle:hintslight",
    "JoyPixels:pixelsize=24:antialias=true:autohint=true:hintstyle:hintslight",
};
static const char dmenufont[]       = "monospace:pixelsize=24:antialias=true:autohint:false:hint:ture:hintstyle:hintslight";

#define wal "/home/liubianshi/.cache/wal/colors-wal-dwm.h" 
#if __has_include(wal)
#include wal
#else
static const char *colors[][3]      = {
static const char col_gray1[] = "#031B29";
static const char col_gray2[] = "#909188";
static const char col_gray3[] = "#ced0c3";
static const char col_gray4[] = "#98A695";
static const char col_cyan1[] = "#505A5B";
static const char col_cyan2[] = "#8E765A";
static const char col_cyan3[] = "#D9AF64";

static const char *colors[][3]      = {
    /*               fg           bg           border                         */
    [SchemeNorm] = { col_gray3,   col_gray1,   col_gray2 }, // unfocused wins
    [SchemeSel]  = { col_gray4,   col_cyan1,   col_cyan3 },  // the focused win
    [SchemeUrg]  = { col_gray4,   col_cyan2,   col_cyan2 },
    [SchemeHid]  = { col_cyan1,   col_gray1,   col_gray2}, 
};
#endif

/* tagging */
//static const char *tags[] = { "1", "2", "3", "4", "5", "6", "7", "8", "9" };
static const char *tags[] = { "1 \uf120", "2 \uf7ae", "3 \uf121", "4 \uf04b", "5 \ue62e", "6 \uf251", "7 \ue727", "8 \uf537", "9 \uf684" };

static const Rule rules[] = {
    /* xprop(1):
     *  WM_CLASS(STRING) = instance, class
     *  WM_NAME(STRING) = title
     */
	/* class          instance    title       tags mask     isfloating  isterminal  noswallow  monitor scratch key*/
	{ "Gimp",         NULL,       NULL,       0,            1,          0,           0,        -1,      0},
	{ "Firefox",      NULL,       NULL,       1 << 8,       0,          0,          -1,        -1,      0},
	{ "St",           NULL,       NULL,       0,            0,          1,           0,        -1,      0},
	{ "Alacritty",    NULL,       NULL,       0,            0,          1,           0,        -1,      0},
	{ NULL,           NULL,  "Event Tester",  0,            1,          0,           1,        -1,      0}, /* xev */
    { "fzfmenu",      NULL,       NULL,       0,            1,          0,           1,        -1,      0},
    { "Xfce4-appfinder", NULL,    NULL,       0,            1,          0,           1,        -1,      0},
    { "VirtualBox Machine", NULL, NULL,       0,            1,          0,           1,        -1,      0},
    { "ncmpcpp",      NULL,       NULL,       0,            1,          0,           1,        -1,      0},
    { "blueman-manager", NULL,    NULL,       0,            1,          0,           1,        -1,      0},
    { NULL, "netease-cloud-music-gtk",  NULL, 0,            1,          0,           1,        -1,      0},
    { NULL, "netease-cloud-music",      NULL, 0,            1,          0,           1,        -1,      0},
    { "Zotero",       NULL,       NULL,       1 << 3,       0,          0,           0,        -1,      0},
    { "Okular",       NULL,       NULL,       1 << 5,       0,          0,           0,        -1,      0},
    { "Wps",          NULL,       NULL,       1 << 2,       0,          0,           0,        -1,      0},
    { "Steam",        NULL,       NULL,       1 << 6,       0,          0,           0,        -1,      0},
    { "TelegramDesktop", NULL,    NULL,       1 << 6,       0,          0,           0,        -1,      0},
    { "Vmplayer",     NULL,       NULL,       1 << 7,       0,          0,           0,        -1,      0},
    { "Zenity",       NULL,       NULL,       0,            1,          0,           1,        -1,      0},
    { "Display", "display",       NULL,       0,            1,          0,           1,        -1,      0},
    { "scrcpy",   "scrcpy",       NULL,       1 << 6,       1,          0,           1,        -1,      0},
    { "Emacs", "emacs", "doom-capture",       0,            1,          0,           1,        -1,      0},
    { "copyq",        NULL,       NULL,       0,            1,          0,           1,        -1,      0},
    { "R_x11",        NULL,       NULL,       0,            1,          0,           1,        -1,      0},
    { "qutebrowser",  NULL,       NULL,       1 << 1,       0,          0,          -1,        -1,      0},
    { "Brave-browser", NULL,      NULL,       1 << 1,       0,          0,          -1,        -1,      0},
    { NULL,           NULL,     "scratchpad", 0,            1,          0,          -1,        -1,    's'},
};

/* layout(s) */
static const float mfact     = 0.62; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 1;    /* 1 means respect size hints in tiled resizals */
static const int lockfullscreen = 1; /* 1 will force focus on the fullscreen window */

#define FORCE_VSPLIT 1  /* nrowgrid layout: force two clients to always split vertically */
#include "vanitygaps.c"
#include "focusurgent.c"

static const Layout layouts[] = {
    /* symbol     arrange function */
    { "=[]",      tile },    /* first entry is default */
    { "><>",      NULL },    /* no layout function means floating behavior */
    { "[M]",      monocle },
    { "[@]",      spiral },
    { "[\\]",     dwindle },
    { "|M|",      centeredmaster },
    { ">M>",      centeredfloatingmaster },
    { "[D]",      deck },
	{ "TTT",      bstack },
	{ "===",      bstackhoriz },
	{ "HHH",      grid },
	{ "###",      nrowgrid },
	{ "---",      horizgrid },
	{ ":::",      gaplessgrid },
	{ NULL,       NULL },
};

/* key definitions */
#define MODKEY Mod4Mask
#define TAGKEYS(KEY,TAG) \
    { MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
    { MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
    { MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
    { MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },
#define STACKKEYS(MOD,ACTION) \
    { MOD, XK_j,     ACTION##stack, {.i = INC(+1) } }, \
    { MOD, XK_k,     ACTION##stack, {.i = INC(-1) } }, \
    { MOD, XK_h,     ACTION##stack, {.i = 0 } }, \
    { MOD, XK_Tab,   ACTION##stack, {.i = PREVSEL } }, \
    { MOD, XK_x,     ACTION##stack, {.i = -1 } }, \
    { MOD, XK_l,     ACTION##stack, {.i = 1 } }, 

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }
#define STATUSBAR "dwmblocks"

/* commands */
static char dmenumon[2] = "0"; /* component of dmenucmd, manipulated in spawn() */
static const char *dmenucmd[] = { "dmenu_run", "-m", dmenumon, "-fn", dmenufont, "-nb", col_gray1, "-nf", col_gray3, "-sb", col_cyan2, "-sf", col_gray1, NULL };
static const char *termcmd[]  = { "st", NULL };
static const char scratchpadname[] = "scratchpad";
// static const char *scratchpadcmd[] = { "s", "alacritty", "-t", scratchpadname, "-o", "window.dimensions.columns=127", "window.dimensions.lines=20", NULL };
static const char *scratchpadcmd[] = { "s", "st", "-t", scratchpadname, "-g", "127x20+350+10", NULL };
static Key keys[] = {
    /* modifier                      key        function        argument */
    STACKKEYS(MODKEY,                focus)
    STACKKEYS(MODKEY|ShiftMask,      push)
    TAGKEYS( XK_1, 0 )
    TAGKEYS( XK_2, 1 )
    TAGKEYS( XK_3, 2 )
    TAGKEYS( XK_4, 3 )
    TAGKEYS( XK_5, 4 )
    TAGKEYS( XK_6, 5 )
    TAGKEYS( XK_7, 6 )
    TAGKEYS( XK_8, 7 )
    TAGKEYS( XK_9, 8 )
    { MODKEY,                        XK_0,      view,           {.ui = ~0 } },
    { MODKEY|ShiftMask,              XK_0,      tag,            {.ui = ~0 } },
    { MODKEY,                        XK_q,      killclient,     {0} },
    { MODKEY|ShiftMask,              XK_q,      quit,           {0} },
    { MODKEY|ControlMask|ShiftMask,  XK_q,      quit,           {1} },
    { MODKEY,                        XK_r,      spawn,          {.v = dmenucmd } },
    { MODKEY,                        XK_f,      togglefullscr,  {0} },
    { MODKEY,                        XK_space,  zoom,           {0} },
    { MODKEY|ShiftMask,              XK_space,  togglefloating, {0} },
    
    { MODKEY,                        XK_t,      setlayout,      {.v = &layouts[0]} },
    { MODKEY|ControlMask,            XK_space,  setlayout,      {.v = &layouts[1]} },
    { MODKEY|ShiftMask,              XK_t,      setlayout,      {.v = &layouts[2]} },
    { MODKEY,                        XK_d,      setlayout,      {.v = &layouts[7]} },
    { MODKEY,                        XK_i,      incnmaster,     {.i = +1 } },
    { MODKEY|ShiftMask,              XK_i,      incnmaster,     {.i = -1 } },

    { MODKEY,                        XK_a,      setmfact,       {.f = +0.02} },
    { MODKEY|ShiftMask,              XK_a,      setmfact,       {.f = -0.02} },

    { MODKEY,                        XK_Return, spawn,          {.v = termcmd } },
    { MODKEY|ShiftMask,              XK_Return, togglescratch,  {.v = scratchpadcmd } },
    { MODKEY,                        XK_b,      togglebar,      {0} },



    { MODKEY|ShiftMask,             XK_bracketleft,  focusstackhid,    {.i = +1 } },
    { MODKEY|ShiftMask,             XK_bracketright, focusstackhid,    {.i = +1 } },
    { MODKEY,                       XK_bracketright, hide,       {0} },
    { MODKEY,                       XK_bracketleft,  show,       {0} },
	{ MODKEY|Mod1Mask,              XK_j,        rotatestack,    {.i = +1 } },
	{ MODKEY|Mod1Mask,              XK_k,        rotatestack,    {.i = -1 } },

    { MODKEY,                       XK_Left,     focusmon,       {.i = -1 } },
    { MODKEY,                       XK_Right,    focusmon,       {.i = +1 } },
    { MODKEY|ShiftMask,             XK_Left,     tagmon,         {.i = -1 } },
    { MODKEY|ShiftMask,             XK_Right,    tagmon,         {.i = +1 } },

	{ MODKEY,                       XK_u,       focusurgent,     {0} },
	{ MODKEY,                       XK_s,       scratchpad_show, {.i = 1} },
	{ MODKEY,                       XK_y,       scratchpad_show, {.i = 2} },
	{ MODKEY,                       XK_u,       scratchpad_show, {.i = 3} },
	{ MODKEY|ShiftMask,             XK_s,       scratchpad_hide, {.i = 1} },
	{ MODKEY|ShiftMask,             XK_y,       scratchpad_hide, {.i = 2} },
	{ MODKEY|ShiftMask,             XK_u,       scratchpad_hide, {.i = 3} },
	{ MODKEY|ShiftMask,             XK_r,       scratchpad_remove,    {0} },
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
	{ ClkWinTitle,          0,              Button1,        togglewin,      {0} },
	{ ClkWinTitle,          0,              Button2,        zoom,           {0} },
	{ ClkStatusText,        0,              Button1,        sigstatusbar,   {.i = 1} },
	{ ClkStatusText,        0,              Button2,        sigstatusbar,   {.i = 2} },
	{ ClkStatusText,        0,              Button3,        sigstatusbar,   {.i = 3} },
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
};

void
setlayoutex(const Arg *arg)
{
	setlayout(&((Arg) { .v = &layouts[arg->i] }));
}

void
viewex(const Arg *arg)
{
	view(&((Arg) { .ui = 1 << arg->ui }));
}

void
viewall(const Arg *arg)
{
	view(&((Arg){.ui = ~0}));
}

void
toggleviewex(const Arg *arg)
{
	toggleview(&((Arg) { .ui = 1 << arg->ui }));
}

void
tagex(const Arg *arg)
{
	tag(&((Arg) { .ui = 1 << arg->ui }));
}

void
toggletagex(const Arg *arg)
{
	toggletag(&((Arg) { .ui = 1 << arg->ui }));
}

void
tagall(const Arg *arg)
{
	tag(&((Arg){.ui = ~0}));
}

/* signal definitions */
/* signum must be greater than 0 */
/* trigger signals using `xsetroot -name "fsignal:<signame> [<type> <value>]"` */
static Signal signals[] = {
	/* signum           function */
    { "defaultgaps",    defaultgaps }, /* reset gaps back to default */
	{ "focusmon",       focusmon },
	{ "focusstack",     focusstackvis },
	{ "focusurgent",    focusurgent }, 
    { "incrgaps",       incrgaps },    /* increase all gaps */
    { "incrigaps",      incrigaps },   /* increase  inner gaps */
    { "incrihgaps",     incrihgaps },  /* increase inner horizontal gaps */
    { "incrivgaps",     incrivgaps },  /* increase inner horizontal gaps */
    { "incrogaps",      incrogaps },   /* increase outer gaps */
    { "incrohgaps",     incrohgaps },  /* increase outer horizontal gaps */
    { "incrovgaps",     incrovgaps },  /* increase outer vertical gaps */
	{ "incnmaster",     incnmaster },
	{ "killclient",     killclient },
	{ "quit",           quit },
	{ "setlayout",      setlayout },
	{ "setlayoutex",    setlayoutex },
	{ "setmfact",       setmfact },
	{ "tag",            tag },
	{ "tagall",         tagall },
	{ "tagex",          tagex },
	{ "togglebar",      togglebar },
	{ "togglefloating", togglefloating },
    { "togglegaps",     togglegaps },  /* toggle gaps on and off */
	{ "toggletag",      tag },
	{ "toggletagex",    toggletagex },
	{ "toggleview",     view },
	{ "toggleviewex",   toggleviewex },
	{ "tagmon",         tagmon },
	{ "view",           view },
	{ "viewall",        viewall },
	{ "viewex",         viewex },
	{ "zoom",           zoom },
};
