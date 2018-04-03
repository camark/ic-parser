# ic-parser

一套简易的串口IC卡读卡器协议解析代码。称不上是库，随手封装而已。之所以用C写，是考虑跨平台在任意系统任意场景下使用。

协议文档是淘宝卖家发来的，几乎适用于市面上所有的串口IC读卡器（只能读出UID的那种），不适用于ACR122U等USB读卡器（能读写数据）。

最后丢两个淘宝链接吧：

<https://item.taobao.com/item.htm?spm=a230r.1.14.41.446e674c8pjbyj&id=535424465212&ns=1&abbucket=11#detail>

<https://item.taobao.com/item.htm?spm=a230r.1.14.28.2a3a3925raXI9x&id=25652956508&ns=1&abbucket=11#detail>