# DWM build
### Patches, bindings, autism.

#### Patches:
- [Hide Vacant Tags](https://dwm.suckless.org/patches/hide_vacant_tags/)
- [Dynamic Swallow](https://dwm.suckless.org/patches/dynamicswallow/)
- [Scratchpads](https://dwm.suckless.org/patches/scratchpads/)
- [Stacker](https://dwm.suckless.org/patches/stacker/)
- [Vanity Gaps](https://dwm.suckless.org/patches/vanitygaps/)

#### Unique Bindings
> Window Swallowing
- _ModKey + U_ = **Split swallower and swallowe**

For the rest, refer to this [Tutorial](https://www.youtube.com/watch?v=iB4aBY0H_oI) for a good guide by a euroman

**tl;dw**
map your programs to `dwmswallow $WINDOWID; *Program Name*` in your .bashrc

> Scratchpads
- _ModKey + Shift + P_ = **KeePassXC**

> Stacker

Two parallel sets of bindings; _MODKEY_ for **focus** and _MODKEY + Shift_ for **push**.
| Key | Description |
| ----------- | ----------- |
| *K* | Up Stack |
| *J* | Down Stack |
| *Q* | First Position |
| *A* | Second Position |
| *Z* | Third Position |
| *X* | Last Position |

> Vanity Gaps
- _ModKey + Minus_ = **Toggle Gaps**
- _ModKey + Shift + Minus_ = **Reset Gaps**
- _ModKey + Plus_ = **Reduce Gaps**
- _ModKey + Shift + Plus_= **Increase Gaps**

> Others
- _ModKey + F_ = **File Manager**
- _ModKey + W_ = **Browser**
- _ModKey + Escape_ = **Quit DWM**
