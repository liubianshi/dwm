# 给 dwm 打补丁

## [autostart](https://dwm.suckless.org/patches/autostart/)

```sh
wget 'https://dwm.suckless.org/patches/autostart/dwm-autostart-20210120-cb3f58a.diff'
patch -i dwm-autostart-20210120-cb3f58a.diff
rm *.orig
git add .
git commit -m "patch autostart"
```

