# 给 dwm 打补丁

## [autostart](https://dwm.suckless.org/patches/autostart/)

This patch will make dwm run "~/.dwm/autostart_blocking.sh" and
"~/.dwm/autostart.sh &" before entering the handler loop. One or both of these
files can be ommited.

```sh
wget 'https://dwm.suckless.org/patches/autostart/dwm-autostart-20210120-cb3f58a.diff'
patch -i dwm-autostart-20210120-cb3f58a.diff
rm *.orig
git add .
git commit -m "patch autostart"
```

## [dwmc](https://dwm.suckless.org/patches/dwmc/)

Simple dwmc client using a fork of fsignal to communicate with dwm.

```sh
wget https://dwm.suckless.org/patches/dwmc/dwm-dwmc-6.2.diff
patch -i dwm-dwmc-6.2.diff
git add .
git commit -m "patch dwmc"
```

## [focusurgent](https://dwm.suckless.org/patches/focusurgent/)


- Selects the next window having the urgent flag regardless of the tag it is on
- The urgent flag can be artificially set with the following xdotool command on
  any window: xdotool selectwindow -- set_window --urgency 1

```sh
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

```sh
wget https://dwm.suckless.org/patches/statuscmd/dwm-statuscmd-20210405-67d76bd.diff
patch -i dwm-statuscmd-20210405-67d76bd.diff
```

调整以适应 [dwmblocks-async](https://github.com/UtkarshVerma/dwmblocks-async)

```sh
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

```sh
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

```sh
wget https://dwm.suckless.org/patches/systray/dwm-systray-6.3.diff
patch -i ./dwm-systray-6.3.diff
```

手动处理没有自动完成的补丁!

```sh
git add .
git commit -m "systray"
```



