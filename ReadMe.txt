配列コピー速度比較
Array copy speed comparison

1次元配列の内容をコピーする。
使用する関数や、反復子の使い方によるコピー速度の違いを調査しました。
・標準関数　memcpy()　によるコピー
・while() ループによるコピー
・foe() ループによるコピー


環境
・Windows10 64bit
・Intel Core i7-10700
・VisualStudio 2013

1000byteの配列をコピーする。
コピーを1000000回繰り返した期間をそてぞれの条件で計測した。

＜実行結果＞

私が測定した環境では以下のようになりました。
環境によって違いはあると思います。

==== Copy Speed Comparison START ====
Number of loops : 1000000
memcpy copy time        : 17 ms
while loop copy time    : 1452 ms
for loop copy time      : 2019 ms
==== Copy Speed Comparison END ====

所感
・memcpy()は非常に高速にコピーが行われるようだ。
　ハードウエアを使用してコピーが行われるのだろう。
・whileループは、for()ループに比べて1回のループあたりの足し算が1個少なくできている為速いかったのだろう。

