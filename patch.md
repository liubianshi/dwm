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
git commmit -m "patch rotate stack"
```





