={tips} Tips
拙著「Twitter Application on Kotlin」を執筆中に追加した打ち消し線機能と、
TeX記法の表紙の作成について記載します。
本章では、@<chap>{how_to_build}においてクローンしたReVIEW-Templateを使用しているものとします。

== 打ち消し線（取り消し線）
あとがきなど、ちょっとくだけた文章では@<del>{こんな感じの}打ち消し線を
導入したくなることがあるかも知れません。
インライン命令の@<code>{＠＜del＞｛｝}はデフォルトで入ってはいますが、Re:VIEWの中では現状何もせずに出力がされるようです。
この打ち消し線を導入します@<fn>{ruby_ex}。

//footnote[ruby_ex][Rubyを拡張する方法もあるようですが、スタイルファイルを修正するのが一番簡単でした。]

ReVIEW-Templateには、最初から打ち消し線に必要なスタイルファイルが同梱されています。

 * jumoline.sty

打ち消し線を有効にするために、techbooster-doujin.styに次の文を追加します。

//listnum[techbooster][techbooster-doujin.sty]{
\usepackage{jumoline}
\renewcommand{\reviewstrike}[1]{\Midline{#1}}
//}

これで@<code>{＠＜del＞｛｝}の中括弧で囲んだ部分に打ち消し線が引かれます。
ただ、筆者はデフォルトの線の高さだとわずかに高いと感じたので、高さを微調整してみました。
jimoline.styの次の数値を修正します。

//listnum[jumoline][jumoline.sty]{
#「.5」を「.4」に修正
\def\Midline{\setbox\@tempboxa\hbox{あ}%
        \UMO@line\MidlineHeight\MidlineHeight{.5\ht\@tempboxa}}
    ↓
\def\Midline{\setbox\@tempboxa\hbox{あ}%
        \UMO@line\MidlineHeight\MidlineHeight{.4\ht\@tempboxa}}
//}

お好みに応じて修正しましょう。

== 表紙をTeXで作る
ReVIEW-Templateではconfig.ymlのbooktitleを修正するだけで簡単に表紙を作ることができます。
しかし表題の任意の位置での改行ができなかったり、レイアウトの自由が効かないことが気になるかもしれません。
そこで、cover.texを作ってTeX記法でレイアウトを組み立てます。

//listnum[cover][cover.tex]{
\begin{titlepage}
    \centering{\vspace*{\stretch{1}}
        \Huge\bfseries
        Twitter Apprication\\
        on Kotlin\\
        \vspace{\stretch{2}}
    }
    \vfill\vspace{6ex}{
        \Large
        KC 著
    \par}
    \vfill
    \parbox[c]{\hsize}{
        \centering\large
        2018-10-08版　くり返す日常 発行\\
        \vspace{6ex}{
            \footnotesize
            1
        }
    }
\end{titlepage}
//}

@<list>{cover}は、冒頭の拙著のcover.texのコードになります。
TeX記法は書き出すとキリが無いので、申し訳ありませんが本書では割愛させていただきます。
cover.texをarticlesフォルダに配置したら、config.ymlを修正します。

//listnum[config_cover][config.yml]{
# 表紙にするHTMLファイル。ファイル名を指定すると表紙として入る
# cover: null
　↓
cover: cover.html
//}

拡張子は「.html」と記述してください。
PDFにコンパイルすると@<img>{img_cover}のように表示されます。

//image[img_cover][cover.tex][scale=0.5]{
//}

表紙も自由に組み立てて、みんなでRe:VIEWやっていき！です@<fn>{yatteiki}。

//footnote[yatteiki][言ってみたかっただけです]

