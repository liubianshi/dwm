# 给 dwm 打补丁

## [autostart](https://dwm.suckless.org/patches/autostart/)

This patch will make dwm run "~/.dwm/autostart_blocking.sh" and
"~/.dwm/autostart.sh &" before entering the handler loop. One or both of these
files can be ommited.

```bash
wget 'https://dwm.suckless.org/patches/autostart/dwm-autostart-20210120-cb3f58a.diff'
patch -i dwm-autostart-20210120-cb3f58a.diff
rm *.orig
git add .
git commit -m "patch autostart"
```

## [dwmc](https://dwm.suckless.org/patches/dwmc/)

Simple dwmc client using a fork of fsignal to communicate with dwm.

```bash
wget https://dwm.suckless.org/patches/dwmc/dwm-dwmc-6.2.diff
patch -i dwm-dwmc-6.2.diff
git add .
git commit -m "patch dwmc"
```

## [focusurgent](https://dwm.suckless.org/patches/focusurgent/)


- Selects the next window having the urgent flag regardless of the tag it is on
- The urgent flag can be artificially set with the following xdotool command on
  any window: xdotool selectwindow -- set_window --urgency 1

```bash
wget 'https://dwm.suckless.org/patches/focusurgent/dwm-focusurgent-20160831-56a31dc.diff'
patch -i dwm-focusurgent-20160831-56a31dc.diff
git add .
git commit -m "focusurgent"
```

## [statuscmd](https://dwm.suckless.org/patches/statuscmd/)

This patch adds the ability to signal a status monitor program such as
dwmblocks the location and button when clicking on the status bar.
Alternatively, there is a version that executes shell commands defined in
config.h instead of using signals.

```bash
wget https://dwm.suckless.org/patches/statuscmd/dwm-statuscmd-20210405-67d76bd.diff
patch -i dwm-statuscmd-20210405-67d76bd.diff
```

调整以适应 [dwmblocks-async](https://github.com/UtkarshVerma/dwmblocks-async)

```bash
rg 'fp = popen' dwm.c
sed -Ei 's/popen\("pidof -s "STATUSBAR/popen("pgrep -o "STATUSBAR/' ./dwm.c
```

保存修改

```bash
git add .
git commit -m "patch statuscmd"
```

# [restartsig](https://dwm.suckless.org/patches/restartsig/)

dwm can now be restarted via MOD+CTRL+SHIFT+Q or by kill -HUP dwmpid

In addition, a signal handler was added so that dwm cleanly quits by kill -TERM dwmpid.

```bash
wget https://dwm.suckless.org/patches/restartsig/dwm-restartsig-20180523-6.2.diff
patch -i dwm-restartsig-20180523-6.2.diff
```

手动处理没有自动完成的补丁, 处理完成后, 测试是否存在问题. 在处理冲突的过程中, 调整快捷键
通过 MOD+SHIFT+Q 重启 dwm, 但不重启整个系统, 而通过 MOD+CTRL+SHIFT+Q 重启整个系统.

```bash
git add .
git commit -m "restartsig"
```

# [systray](https://dwm.suckless.org/patches/systray/)

A simple system tray implementation. Multi-monitor is also supported. The tray
follows the selected monitor.

In case icons disappear when toggling the bar, try a different font size in
dwm. This has helped at least in one case with pidgin.

```bash
wget https://dwm.suckless.org/patches/systray/dwm-systray-6.3.diff
patch -i ./dwm-systray-6.3.diff
```

手动处理没有自动完成的补丁!

```bash
git add .
git commit -m "systray_adjust"
```

注意 drawbar 函数, 同时打 systray 和 statuscmd 这两个补丁时, 容易出现非常诡异的问题. 
所以还需要做一些手动调整.


# [awesomebar](https://dwm.suckless.org/patches/awesomebar/)

```bash
wget https://dwm.suckless.org/patches/awesomebar/dwm-awesomebar-20200907-6.2.diff
patch -i dwm-awesomebar-20200907-6.2.diff
```

存在冲突, 需要手动解决冲突。

```bash
git add .
git commit -m "awesomebar"
```

# [actualfullscreen](https://dwm.suckless.org/patches/actualfullscreen/)

Actually toggle fullscreen for a window, instead of toggling the status bar and
the monocle layout.

```bash
wget 'https://dwm.suckless.org/patches/actualfullscreen/dwm-actualfullscreen-20191112-cb3f58a.diff'
patch -i ./dwm-actualfullscreen-20191112-cb3f58a.diff
git add .
git commit -m "actualfullscreen"
```

# [hide vacant tags](https://dwm.suckless.org/patches/hide_vacant_tags/)

This patch prevents dwm from drawing tags with no clients (i.e. vacant) on the bar.

```bash
wget https://dwm.suckless.org/patches/hide_vacant_tags/dwm-hide_vacant_tags-6.2.diff
patch -i ./dwm-hide_vacant_tags-6.2.diff
git add .
git commit -m "pathc hide-vacant-tags"
```

# [pertag](https://dwm.suckless.org/patches/pertag/)

More general approach to taglayouts patch. This patch keeps layout, mwfact,
barpos and nmaster per tag.

```bash
wget https://dwm.suckless.org/patches/pertag/dwm-pertag-20200914-61bb8b2.diff
patch -i ./dwm-pertag-20200914-61bb8b2.diff
git add .
git commit -m "patch pertag"
```

# [vanitygaps](https://dwm.suckless.org/patches/vanitygaps/)

Inspired by some of the functionality of i3-gaps this patch adds (inner) gaps between client windows and (outer) gaps between windows and the screen edge in a flexible manner.

```bash
wget https://dwm.suckless.org/patches/vanitygaps/dwm-vanitygaps-6.2.diff
patch -i ./dwm-vanitygaps-6.2.diff
git add .
git commit -m "vanitygaps"
```

# [viewontag](https://dwm.suckless.org/patches/viewontag/)

Follow a window to the tag it is being moved to.

```bash
wget https://dwm.suckless.org/patches/viewontag/dwm-viewontag-20210312-61bb8b2.diff
patch < ./dwm-viewontag-20210312-61bb8b2.diff
git add .
git commit -m "viewontag"
```

# [rotatestack](https://dwm.suckless.org/patches/rotatestack/)

Stack rotation moves a client from the bottom to the top of the stack (or the
other way round). This effectively rotates the clients by one position
clockwise (or CCW, respectively).

It should play well with arbitrary stack layouts and nmaster values.

One may think of it as moving the zoom through the list of clients, very much
in the same way as scrolling moves the view port around a pane.

```bash
wget https://dwm.suckless.org/patches/rotatestack/dwm-rotatestack-20161021-ab9571b.diff
patch < ./dwm-rotatestack-20161021-ab9571b.diff
git add .
git commit -m "patch rotate stack"
```

# [stacker](https://dwm.suckless.org/patches/stacker/)


This patch provides comprehensive utilities for managing the client stack. It
implements two new commands: focusstack (which is a replacement for the
original focusstack command) and pushstack. The first one is for focusing
clients while the second one moves clients around the stack. Both commands take
the same kind of argument:

- Pass PREVSEL to focus/push the previously selected client in the current
  tagset.
- Pass INC(+/-inc) to focus/push relatively to the selected client. This will
  wrap around the stack limits.
- Pass a positive number to focus/push relatively to the beginning of the
  stack. Out of limit values will be truncated to the position of the last
  visible client and won't wrap around.
- Pass a negative number to focus/push relatively to the last visible client in
  the stack. Here -1 means the last client, -2 the previous to last client,
  etc. Out of limit values will be truncated to the position of the first
  visible client (0) and won't wrap around.

```bash
wget https://dwm.suckless.org/patches/stacker/dwm-stacker-6.2.diff
patch < ./dwm-stacker-6.2.diff
```

与 awesomebar 有严重的冲突, 注意修正

```bash
git add .
git commit -m "patch stacker"
```

# [warp](https://dwm.suckless.org/patches/warp/)


This patch warps the mouse cursor to the center of the currently focused window
or screen when the mouse cursor is (a) on a different screen or (b) on top of
a different window.

```bash
wget https://dwm.suckless.org/patches/warp/dwm-warp-6.2.diff
patch < ./dwm-warp-6.2.diff
git add .
git commit -m "warp"
```

# [namedscratchpads](https://dwm.suckless.org/patches/namedscratchpads/)

Allows for the creation of multiple scratchpad windows, each assigned to
different keybinds.

On pressing the keybind the window will either:

- Spawn based on the given command, if it's not already running
- Toggle visibility of the window

A new field in the rules array is added to associate the command with the
corresponding rule.

```bash
wget https://dwm.suckless.org/patches/namedscratchpads/dwm-namedscratchpads-6.2.diff
patch < ./dwm-namedscratchpads-6.2.diff
```

存在冲突, 需要合并

```bash
git add .
git commit -m "namedscratchpads"
```

# [multipledynamicscratchpads](https://dwm.suckless.org/patches/multipledynamicscratchpads/)

```bash
wget https://dwm.suckless.org/patches/multipledynamicscratchpads/dwm-multiple-dynamic-scratchpads.diff
patch < ./dwm-multiple-dynamic-scratchpads.diff
```

存在冲突, 需要合并

```bash
git add .
git commit -m "multipledynamicscratchpads"
```


# [swallow](https://dwm.suckless.org/patches/swallow/)

This patch adds "window swallowing" to dwm as known from Plan 9's windowing
system rio.

Clients marked with isterminal in config.h swallow a window opened by any child
process, e.g. running xclock in a terminal. Closing the xclock window restores
the terminal window in the current position.

This patch helps users spawning a lot of graphical programs from their command
line by avoiding cluttering the screen with many unusable terminals. Being deep
down in a directory hierarchy just does not make the use of dmenu feasible.

```bash
wget https://dwm.suckless.org/patches/swallow/dwm-swallow-20201211-61bb8b2.diff
patch < ./dwm-swallow-20201211-61bb8b2.diff
```

# [custom urgent border](https://dwm.suckless.org/patches/urgentborder/)


This patch makes borders of "urgent" windows a different color. By default it
is bright red. Use config.h item "urgbordercolor" to change it.

```bash
wget https://dwm.suckless.org/patches/urgentborder/dwm-6.2-urg-border.diff
patch < ./dwm-6.2-urg-border.diff
git add .
git commit -m "patch swallow and urg-border"
```

# [deck](https://dwm.suckless.org/patches/deck/)

deck is a dwm-layout which is inspired by the TTWM window manager. It applies
the monocle-layout to the clients in the stack. The master-client is still
visible. The stacked clients are like a deck of cards, hence the name.

实际上 vanitygaps 已经包含了各种 layout 模式了，其中包含了 deck

# [pango](https://dwm.suckless.org/patches/pango/)

```bash
wget https://dwm.suckless.org/patches/pango/dwm-pango-20201020-519f869.diff
patch < ./dwm-pango-20201020-519f869.diff
```

打补丁的难度非常高，而且是破坏性的，同时，他也没有什么特别的功能，所以不值得安装。

# [status2d](https://dwm.suckless.org/patches/status2d/)

能够在 status bar 输出不同的颜色.

```bash
wget https://dwm.suckless.org/patches/status2d/dwm-status2d-6.2.diff
patch < ./dwm-status2d-6.2.diff
```

