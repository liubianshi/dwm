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


