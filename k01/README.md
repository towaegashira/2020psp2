# 課題 1 レポート

aa83988848 薗田光太郎

## 課題

標本男性の平均と分散を求めよ．また，「適当に選んだ」と言っても所詮聞く相手は周辺の同年代の同じ学部の友達に限定されそうである．周辺に住んでる同年代の工学部の男性の平均と分散を推定せよ．また，この推定される平均値は標本のとるたびに異なるので確率変数であり，今回推定した平均には誤差がある．その誤差（標準誤差）を求めよ．
   
標本平均<img src="/k01/tex/33717a96ef162d4ca3780ca7d161f7ad.svg?invert_in_darkmode&sanitize=true" align=middle width=9.39498779999999pt height=18.666631500000015pt/>は<img src="/k01/tex/62b894bfb44d2b063162fb22902c5464.svg?invert_in_darkmode&sanitize=true" align=middle width=109.25130645pt height=43.42856099999997pt/>で求められる．また，標本分散<img src="/k01/tex/f8c439f4893e23a4e7a8d09507bd0082.svg?invert_in_darkmode&sanitize=true" align=middle width=14.25802619999999pt height=26.76175259999998pt/>は<img src="/k01/tex/99b526b607166477d1a8cfbed3ba27b1.svg?invert_in_darkmode&sanitize=true" align=middle width=164.58227939999998pt height=43.42856099999997pt/>もしくは，<img src="/k01/tex/f5b0825f5bfa1b5c1738c1014075e5d6.svg?invert_in_darkmode&sanitize=true" align=middle width=102.59112764999999pt height=31.360807499999982pt/>で求められるのも有名な事実である．

しかし，プログラムでこれを計算する際に少し問題が出てくる可能性がある．実は上述の相加平均というのは先ず総和を計算してみる必要がある．最終的な相加平均はデータと同じくらいに小さく収まるが，総和はバカデカくなる可能性がある．バカデカいと計算機で扱えない数値になる可能性があるのだ．そこでデータを増やすたびに平均を更新していくという方法を取る．つまり今，<img src="/k01/tex/f9c4988898e7f532b9f826a75014ed3c.svg?invert_in_darkmode&sanitize=true" align=middle width=14.99998994999999pt height=22.465723500000017pt/>個のデータがあるわけだが，<img src="/k01/tex/e35caf405a5e9b4afd75a0d338c4dc12.svg?invert_in_darkmode&sanitize=true" align=middle width=43.31036984999999pt height=22.465723500000017pt/>個目までの平均<img src="/k01/tex/c5c0ed8b8025fcf4fced515d8205661e.svg?invert_in_darkmode&sanitize=true" align=middle width=37.86769634999999pt height=18.666631500000015pt/>を使って<img src="/k01/tex/23c4750b22d8eb4653f6d92a9b148ced.svg?invert_in_darkmode&sanitize=true" align=middle width=21.04114979999999pt height=18.666631500000015pt/>を作る関数 `double ave_online(double val,double ave)` を作ってみよう．また分散についても `var_online`を作ってみよう．

<p align="center"><img src="/k01/tex/c6844df0b4a6306cb7eb1bf734ed4c93.svg?invert_in_darkmode&sanitize=true" align=middle width=461.71853639999995pt height=49.315569599999996pt/></p>
   
つまり，<img src="/k01/tex/f22a2f1c337be4beb1f1f5e0ef911e57.svg?invert_in_darkmode&sanitize=true" align=middle width=189.80322735pt height=44.70706679999999pt/>．この場合はバカデカい数値が計算に現れなくなる．
   
分散のほうはどうであろうか．<img src="/k01/tex/e35caf405a5e9b4afd75a0d338c4dc12.svg?invert_in_darkmode&sanitize=true" align=middle width=43.31036984999999pt height=22.465723500000017pt/>個目までの分散<img src="/k01/tex/dca72d5952416399a081461dc157be89.svg?invert_in_darkmode&sanitize=true" align=middle width=36.17818709999999pt height=26.76175259999998pt/>を使って<img src="/k01/tex/34ac2553ddb07b4f0173d7b00d7beff4.svg?invert_in_darkmode&sanitize=true" align=middle width=19.351640549999992pt height=26.76175259999998pt/>を作れるだろうか．
   
<p align="center"><img src="/k01/tex/a7d004a72e4a1ee153aefc6cf40b7667.svg?invert_in_darkmode&sanitize=true" align=middle width=248.53833509999995pt height=33.62942055pt/></p>
と考えたら大きな間違いである．
   
<p align="center"><img src="/k01/tex/d1471055f059612969f03b19b21b9cae.svg?invert_in_darkmode&sanitize=true" align=middle width=699.4521533999999pt height=49.315569599999996pt/></p>
だが，<img src="/k01/tex/fd66eb8c7c7b6e2e3b5bb491cb70a92f.svg?invert_in_darkmode&sanitize=true" align=middle width=122.80621814999999pt height=32.256008400000006pt/>は<img src="/k01/tex/808a43f38591a24867c3ae8460c78e97.svg?invert_in_darkmode&sanitize=true" align=middle width=92.27398949999998pt height=26.76175259999998pt/>ではない．<img src="/k01/tex/c7a04cb0f6e41e25b63b0d907c82994a.svg?invert_in_darkmode&sanitize=true" align=middle width=254.64626385pt height=32.256008400000006pt/>なのだ．

そこで，もう一つの分散の計算方法で考えてみる．

<p align="center"><img src="/k01/tex/b1cf5cc9666673f63964890d3717a06c.svg?invert_in_darkmode&sanitize=true" align=middle width=531.9260562pt height=42.80407395pt/></p>
つまり，<img src="/k01/tex/cc387459ad627ae81e81f24d9d2f16c3.svg?invert_in_darkmode&sanitize=true" align=middle width=45.24213374999999pt height=28.840171800000025pt/>と<img src="/k01/tex/c5c0ed8b8025fcf4fced515d8205661e.svg?invert_in_darkmode&sanitize=true" align=middle width=37.86769634999999pt height=18.666631500000015pt/>と<img src="/k01/tex/819cf0f93ca7b69442bb3e1ea8a270e0.svg?invert_in_darkmode&sanitize=true" align=middle width=21.04114979999999pt height=14.15524440000002pt/>があれば，<img src="/k01/tex/34ac2553ddb07b4f0173d7b00d7beff4.svg?invert_in_darkmode&sanitize=true" align=middle width=19.351640549999992pt height=26.76175259999998pt/>を求める関数ができる．`double var_online(double val, double ave, double square_ave)`

また，母集団の分散<img src="/k01/tex/f9eb4bfe9ecef350d36eb594dff3911b.svg?invert_in_darkmode&sanitize=true" align=middle width=9.41027339999999pt height=14.15524440000002pt/>は標本の分散<img src="/k01/tex/f8c439f4893e23a4e7a8d09507bd0082.svg?invert_in_darkmode&sanitize=true" align=middle width=14.25802619999999pt height=26.76175259999998pt/>と標本サイズ<img src="/k01/tex/f9c4988898e7f532b9f826a75014ed3c.svg?invert_in_darkmode&sanitize=true" align=middle width=14.99998994999999pt height=22.465723500000017pt/>から「推定」できる．所謂，不偏分散である．

<p align="center"><img src="/k01/tex/a11cea52a2d8e58fafdb308f98840cdf.svg?invert_in_darkmode&sanitize=true" align=middle width=263.12654445pt height=47.806078649999996pt/></p>
一方，母集団の平均の推定値は，標本の平均<img src="/k01/tex/33717a96ef162d4ca3780ca7d161f7ad.svg?invert_in_darkmode&sanitize=true" align=middle width=9.39498779999999pt height=18.666631500000015pt/>が最良である．

標準誤差（standard error）は，<img src="/k01/tex/7cf3370ccf734d11f1d835f6a1512a7d.svg?invert_in_darkmode&sanitize=true" align=middle width=37.16830259999999pt height=54.157468200000004pt/>で求めることができる．

したがって，今回の課題について，

|統計量|値|
|---|---|
|標本平均|<img src="/k01/tex/24888b4e629550e584c5749d6e257804.svg?invert_in_darkmode&sanitize=true" align=middle width=45.66227159999998pt height=21.18721440000001pt/>|
|標本分散|<img src="/k01/tex/70fca7b16fd0d8e5da79e199011ede93.svg?invert_in_darkmode&sanitize=true" align=middle width=37.44306224999999pt height=21.18721440000001pt/>|
|母集団平均|<img src="/k01/tex/ffd02cd2a29ee359d050673905b82aaf.svg?invert_in_darkmode&sanitize=true" align=middle width=94.97731484999998pt height=21.18721440000001pt/>|
|母集団分散|<img src="/k01/tex/35ae058b877f36e7384685a2e19cb7e4.svg?invert_in_darkmode&sanitize=true" align=middle width=37.44306224999999pt height=21.18721440000001pt/>|

## ソースコードの説明

l.20: データファイル名を入力させ,fname に格納

l.21:　入力させた文字列の最後にエンターキーが入っているので、fname の文字列の最後をヌル文字'\0'に変換

l.22:　 fname を確認

l.24: fname で指定したファイルの先頭アドレスをファイルポインタ fp に読み込む

l.25: もし fp が NULL だったときは,ファイルを開けなかったので,即座にプログラムを終了

l.30: ファイルを 1 行ずつ buf に読み込む. もし読み込みに成功する限り以下を繰り返す

l.31: buf から数値文字列を実数として val に読み込む

l.34: 自作の ave_online 関数の実行

l.35: 2乗平均square_aveを求める

l.36: 自作の var_online　関数の実行

l.39: 母集団推定分散値 p_var を求める

l.40: 標本平均である ave_online の答えを出力

l.41: 標本分散である var_online の答えを出力

l.42:母集団平均推定値である ave_online の答えを出力

l.43:母集団分散推定値である p_var を出力

l.45: ファイルを閉じる.　閉じれないときは,即座にプログラムを終了

l.52: ave_online の処理を以下の通り行う

l.54: 実行回数-1 をそれまでに求めた ave にかけ,新たに求まった val の数値を足して,実行回数で割り s_ave に代入

l.56: var_online の処理を以下の通り行う

l.57: square_ave から ave の二乗を引いて、その答えを返す

## 入出力結果

$ ./k01
input the filename of sample:../sample/heights_male.csv
the filename of sample: ../sample/heights_male.csv    
[1] var:-0.000000, sq_ave:33808.176900, ave:183.870000
[2] var:4.687225, sq_ave:33021.394250, ave:181.705000 
[3] var:17.650867, sq_ave:32062.230967, ave:179.010000
[4] var:36.674225, sq_ave:31088.400450, ave:176.215000
[5] var:29.878136, sq_ave:30952.397240, ave:175.848000
[6] var:27.671089, sq_ave:30688.848433, ave:175.103333
[7] var:27.715078, sq_ave:30403.723243, ave:174.287143
[8] var:25.361711, sq_ave:30262.659088, ave:173.888750
標本平均：173.888750
標本分散：25.361711
母集団平均推定値；173.888750
母集団分散推定値：28.984812

## 修正履歴

- [l.6-7](k01#L6-7),[l.53](k01.c#L53),[l.56](k01.c#L56): 引数の`i`は整数以外が入力されることはありますか．無いなら`int`にしてください．
- [l.34](k01.c#L34): `i = i + 1.0`としていますが，`i = i + 1`でないのはなぜですか．`i+1.0`は`int`と`double`の演算なので演算結果は高い精度の`double`になります．しかし，それを`i=`で`int`に代入しています．意味がありません．
- [l.35-36](k01.c#L35-36): L35 で演算結果(個数を増やした場合の平均)を`ave`でなく`ret`に代入しているのは，続く L36 で元の`ave`を使う必要があるからだと推測します．ですが，L36 のあとに，`ave = ret;`がないと while ループの間，ずっと`ave`は`0.0`のままです．ループを終える前に`ave = ret;`が必要と思います．
- [l.36](k01.c#L36): `square_ave`は 1 回目のループでは 0 を与えればいいですが，2 回目のループでは，1 人目のデータの 2 乗，3 回目のループでは，1 人目のデータの 2 乗と 2 人目のデータの 2 乗との 2 つの値の平均，....でなければいけません．この計算がどこかに必要です．データの 2 乗に対する ave_online の呼び出しがないといけません．
- [l.54](k01.c#L54): `((i-1.0)*ave+val)/i`というように`i-1.0`としていますが，`i-1`ではないのはなぜですか？異なる型の演算は，高い精度の型になります．`i-1`でも構わないように思うのですが...．何か気になるところがあるでしょうか．
- [l.58-59](k01.c#L58-59): 上記に同様
- [l.39-40](k01.c#L39-40): 数字だけ出力してもわかりません．「標本平均:...」，「標本分散：」「母集団平均推定値」「母集団分散推定値」などとキャプションをつけてください．

[comment #20200507]

- レポートに入出力結果を書く欄を作りました．実際の実行結果をコピペしてください．元々書いてあるものは消していいです．
- コンパイル実行したところ，分散，母集団分散推定値が計算間違いです．var_online の関数が間違っています．また，i/(i-1)は int/int なので，1 となり mans と ans は全く同じ値になります．演算の順番を工夫してください．
- 変数名を工夫してください．ret, ans, mans は意味がわかりません．ret は return，ans は answer だと思いますが曖昧です．


[comment #20200617 moto]
-OKです。