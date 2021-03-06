# 課題2 レポート

aa83988848 薗田光太郎

## 課題

住んでるA県で生まれた（ジモティー）20代の男性の平均と分散が<img src="/k02/tex/d68ce6ca3a5bc0d4119b243192bca39a.svg?invert_in_darkmode&sanitize=true" align=middle width=79.97342429999998pt height=21.18721440000001pt/>,<img src="/k02/tex/597caa4b0247df1b37ce91294b1113a2.svg?invert_in_darkmode&sanitize=true" align=middle width=77.79492434999999pt height=27.89048460000002pt/>と公式発表された．また，隣のB県生まれの男性は，平均と分散が<img src="/k02/tex/84c6fc6280b3b0404c5624c15c7ba8d1.svg?invert_in_darkmode&sanitize=true" align=middle width=80.58012929999998pt height=21.18721440000001pt/>,<img src="/k02/tex/effffe1010d8efef5aafbd109a8ea79c.svg?invert_in_darkmode&sanitize=true" align=middle width=70.18242824999999pt height=27.89048460000002pt/>と公式発表されている．このとき，手元の標本の尤もらしさ（尤度）をA県生まれとB県生まれについて求めよ．実際にはもちろんA県・B県以外の県で生まれる人もいるし，標本の全員が同じ県生まれということはないので，この結果の大小からは何も言えない．
   
まず`double p_stdnorm(double y)`を，平均0，分散1の正規分布（標準正規分布;<img src="/k02/tex/f706189f7c542a8078a8b5dc271260ce.svg?invert_in_darkmode&sanitize=true" align=middle width=51.52970459999999pt height=24.65753399999998pt/>）における値<img src="/k02/tex/deceeaf6940a8c7a5a02373728002b0f.svg?invert_in_darkmode&sanitize=true" align=middle width=8.649225749999989pt height=14.15524440000002pt/>の出現確率を出力する関数を作成せよ．
良く知られているように，平均0，分散1の正規分布に従う値<img src="/k02/tex/deceeaf6940a8c7a5a02373728002b0f.svg?invert_in_darkmode&sanitize=true" align=middle width=8.649225749999989pt height=14.15524440000002pt/>の出現確率は，
<p align="center"><img src="/k02/tex/dcba64f2c044edfdbde5ea3b05906df0.svg?invert_in_darkmode&sanitize=true" align=middle width=122.21369985pt height=37.0017615pt/></p>
である．これを関数化したものが`p_stdnorm`である．

平均<img src="/k02/tex/07617f9d8fe48b4a7b3f523d6730eef0.svg?invert_in_darkmode&sanitize=true" align=middle width=9.90492359999999pt height=14.15524440000002pt/>，分散<img src="/k02/tex/e6718aa5499c31af3ff15c3c594a7854.svg?invert_in_darkmode&sanitize=true" align=middle width=16.535428799999988pt height=26.76175259999998pt/>の正規分布（<img src="/k02/tex/ab37c7ccf43057fff834fa1367d3156f.svg?invert_in_darkmode&sanitize=true" align=middle width=62.35355114999998pt height=26.76175259999998pt/>）の確率密度曲線は標準正規分布<img src="/k02/tex/f706189f7c542a8078a8b5dc271260ce.svg?invert_in_darkmode&sanitize=true" align=middle width=51.52970459999999pt height=24.65753399999998pt/>の確率密度曲線と相似である．相似において，<img src="/k02/tex/f706189f7c542a8078a8b5dc271260ce.svg?invert_in_darkmode&sanitize=true" align=middle width=51.52970459999999pt height=24.65753399999998pt/>における<img src="/k02/tex/deceeaf6940a8c7a5a02373728002b0f.svg?invert_in_darkmode&sanitize=true" align=middle width=8.649225749999989pt height=14.15524440000002pt/>が，<img src="/k02/tex/ab37c7ccf43057fff834fa1367d3156f.svg?invert_in_darkmode&sanitize=true" align=middle width=62.35355114999998pt height=26.76175259999998pt/>における<img src="/k02/tex/332cc365a4987aacce0ead01b8bdcc0b.svg?invert_in_darkmode&sanitize=true" align=middle width=9.39498779999999pt height=14.15524440000002pt/>に対応しているとすると，<img src="/k02/tex/deceeaf6940a8c7a5a02373728002b0f.svg?invert_in_darkmode&sanitize=true" align=middle width=8.649225749999989pt height=14.15524440000002pt/>は<img src="/k02/tex/332cc365a4987aacce0ead01b8bdcc0b.svg?invert_in_darkmode&sanitize=true" align=middle width=9.39498779999999pt height=14.15524440000002pt/>を使って，<img src="/k02/tex/68d6425cfaadabd14aeda684e28f4aa7.svg?invert_in_darkmode&sanitize=true" align=middle width=71.93053724999999pt height=41.4194451pt/>と書ける．この操作を<img src="/k02/tex/332cc365a4987aacce0ead01b8bdcc0b.svg?invert_in_darkmode&sanitize=true" align=middle width=9.39498779999999pt height=14.15524440000002pt/>の「標準化」という．つまり，どんな正規分布上の変数も<img src="/k02/tex/deceeaf6940a8c7a5a02373728002b0f.svg?invert_in_darkmode&sanitize=true" align=middle width=8.649225749999989pt height=14.15524440000002pt/>を求めるとそれは標準正規分布に従う．

尤度とは，標本<img src="/k02/tex/a3dedd496824b6f33a456be5f9917136.svg?invert_in_darkmode&sanitize=true" align=middle width=59.728227899999986pt height=14.15524440000002pt/>と仮定分布<img src="/k02/tex/2ec6e630f199f589a2402fdf3e0289d5.svg?invert_in_darkmode&sanitize=true" align=middle width=8.270567249999992pt height=14.15524440000002pt/>の類似度をあらわす．仮定分布のもとで標本中のデータのそれぞれが同時に出現する同時確率である．尤度<img src="/k02/tex/ddcb483302ed36a59286424aa5e0be17.svg?invert_in_darkmode&sanitize=true" align=middle width=11.18724254999999pt height=22.465723500000017pt/>は

<p align="center"><img src="/k02/tex/b0546b665f9803a72be90a9a55348d3d.svg?invert_in_darkmode&sanitize=true" align=middle width=382.1801676pt height=47.806078649999996pt/></p>

と計算できる．<img src="/k02/tex/2ec6e630f199f589a2402fdf3e0289d5.svg?invert_in_darkmode&sanitize=true" align=middle width=8.270567249999992pt height=14.15524440000002pt/>は仮定した確率密度関数で，<img src="/k02/tex/27e556cf3caa0673ac49a8f0de3c73ca.svg?invert_in_darkmode&sanitize=true" align=middle width=8.17352744999999pt height=22.831056599999986pt/>はその母数．<img src="/k02/tex/2ec6e630f199f589a2402fdf3e0289d5.svg?invert_in_darkmode&sanitize=true" align=middle width=8.270567249999992pt height=14.15524440000002pt/>が正規分布なら，<img src="/k02/tex/27e556cf3caa0673ac49a8f0de3c73ca.svg?invert_in_darkmode&sanitize=true" align=middle width=8.17352744999999pt height=22.831056599999986pt/>は，平均<img src="/k02/tex/07617f9d8fe48b4a7b3f523d6730eef0.svg?invert_in_darkmode&sanitize=true" align=middle width=9.90492359999999pt height=14.15524440000002pt/>と分散<img src="/k02/tex/e6718aa5499c31af3ff15c3c594a7854.svg?invert_in_darkmode&sanitize=true" align=middle width=16.535428799999988pt height=26.76175259999998pt/>である．

## ソースコードの説明
l.26:データファイル名を入力させ、fnameに格納

l.27:　入力させた文字列の最後にエンターキーが入っているので、fname の文字列の最後をヌル文字'\0'に変換

l.28:　 fname を確認

l.30: fname で指定したファイルの先頭アドレスをファイルポインタ fp に読み込む

l.31: もし fp が NULL だったときは,ファイルを開けなかったので,即座にプログラムを終了

l.37: ファイルを 1 行ずつ buf に読み込む. もし読み込みに成功する限り以下を繰り返す

l.38: buf から数値文字列を実数として val に読み込む

l.42:自作のp_normA関数を実行

l.43:Aの尤度をL_Aに格納

l.45:自作のp_normB関数を実行

l.46:Aの尤度をL_Bに格納

l.49:ファイルを閉じる.　閉じれないときは,即座にプログラムを終了

l.54:Aの尤度を出力

l.55:Bの尤度を出力

l.62:自作の関数p_stdnormの処理を以下の通り行う

l.64:2πの平方根を分母、eを’zの2乗を2で割った値’乗’ものを分子として計算する

l.67:自作のLikelihoodA関数の処理を以下の通り実行

l.69:それまでの値から算出されるAの尤度に新たなvalの値から求まる確率密度をかけて、その答えをAの尤度として更新する

l.71:自作のLikelihoodB関数の処理を以下の通り実行

l.73:それまでの値から算出されるBの尤度に新たなvalの値から求まる確率密度をかけて、その答えをBの尤度として更新する






## 入出力結果

```
input the filename of sample:../sample/heights_male.csv
the filename of sample: ../sample/heights_male.csv
L_A: 0.000006
L_B: 0.000002
```

## 修正履歴

[comment #20200624]
- 原則として「ソースコードのmain関数の中に，数値そのものは書かない」ようにしてください．
  ```
  double A_ave=170.8;
  double A_var=pow(5.43,2);
  double B_ave=169.7;
  double B_var=pow(5.5,2);
  ```
  とありますが，これを消して，その代わりに`#include ...`の次の行あたりに，
  ```
  #define A_AVE 170.8
  #define A_VAR 5.43
  #define B_AVE 169.7
  #define B_VAR 5.5
  ```
  と書き`A_ave`などを使う部分で代わりに`A_AVE`などを使うようにします．
  - こうすることで，もしこれらの値を変えたときでも，プログラムの主要な部分に手を加えなくてよくなります．[コーディングのコツです．](../Reference/CodingTips.md)
  - また、A_var=pow(5.43,2);とありますが、sqrt(A_var)としか使用していないので、最初からA_var=5.43でも大丈夫だと思います。(B_varも同じく)

[comment #20200626]
- OKです。書き方バッチリです。

[comment #20200707 sonoda]
- 課題2の完了を確認しました（薗田）