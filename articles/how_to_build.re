={how_to_build} Re:VIEW環境を構築するぞ！
執筆環境を構築します。
最初に必要なソフトをダウンロードしておき、順にインストールしていきます。

== 準備
次のモノを準備します。

 * Ruby Installer
 ** https://rubyinstaller.org/
 * TeX Installer
 ** https://www.ms.u-tokyo.ac.jp/~abenori/soft/abtexinst.html
 * Git for Windows
 ** https://gitforwindows.org/
 * Visual Studio Code（以下、VSCode）
 ** https://code.visualstudio.com/
 * seqsplit.sty（スタイルファイル）
 ** https://www.biwako.shiga-u.ac.jp/sensei/kumazawa/tex/seqsplit.html
 
seqsplitはダウンロードしてもらえれば分かると思いますが、seqsplit.styがそのまま入っているわけではありません。
.insから.styを生成しますが、生成にLaTeXが必要なのでひとまず脇に置いておきましょう。

== 環境構築
=== Rubyのインストール
Re:VIEWリポジトリのdoc/quickstart.ja.mdを見ると、次のように記載されています。

//quote{
Re:VIEWはRuby言語で記述されており、Linux/Unix互換システムで動作します。
Mac OS XおよびWindows Cygwinでも動作可能です。
Ruby gemあるいはGitのいずれかを使ってダウンロード・展開します。
//}

ということで、Rubyをインストールします。

ダウンロードしたRubyInstallerを実行し、OKをポチポチ押していって、
黒い画面が出てきたら1,2,3を順番にすべて実行していきます。

//image[ruby_install][黒い画面になったら１～３を順番に実行][scale=0.6]{
//}

ネットからどんどこファイルをダウンロードするので気長に待ちます。
インストールが終わったら、念のためちゃんとできているか確認します。
コマンドプロンプト（またはPowerShell）を起動して次のコマンドを打ちます。

//cmd{
$ ruby --version
ruby 2.4.4p296 (2018-03-28 revision 63013) [x64-mingw32]
//}

バージョンがきちんと返ってくればOKです。
終わったら次にTeXのインストールです。

=== TeXのインストール
TeX InstallerはHPを見ていただければ分かるように、
本当に「誰にでもインストールできるTeX」です。
基本的に「次へ」や「OK」を押していけば終わりますが、
一点だけ注意が必要な部分のみ記載します（@<img>{download_server}）。

//image[download_server][サーバを選択する][scale=0.6]{
//}

サーバの調子によってはダウンロードがうまくいかない場合があります。
もしダウンロードできないようでしたら別のサーバを選択するか、
時間を置いてやり直してみてください。

そのあとは「次へ」または「OK」をポチっていきます。
最後にインストール結果一覧が出てきますので、各ソフトウェアのインストールに成功していればOKです。

=== Git for Windowsのインストール
VSCodeではバージョン管理にGit for Windowsを使用します。
もしmsys2版Gitを同じ環境で使いたい場合（開発環境と競合する等）、msys2版Gitは……

//quote{
git rev-parse --show-toplevelを実行すると、/から始まるPOSIXシェル環境のパスを返します。
//}

POSIXシェル環境のパスを返されてもWindowsでは困ってしまうので、回避策が必要になります@<fn>{msys2_git}。
msys2版Gitとの共存はなかなか骨なので、本書ではストレートにGit for Windowsを使用します。

さてインストールについては、許諾事項の同意以外は同じくポチポチ
次へを押していただければいいので、特に特記事項はありません。
さくさく行きましょう。

//footnote[msys2_git][http://cad-san.hatenablog.com/entry/2016/01/21/011324]

=== Re:VIEWのインストール
Rubyが導入されているので、次のコマンドでRe:VIEWをインストールします。
インストール後、念のためアップデートもしておきましょう。

//cmd{
$ gem install review
... #インストール中…
$ gem update review
//}

これだけです。
Re:VIEWのディレクトリですが、筆者の環境では次のとおりになっています。

 * C:\Ruby24-x64\lib\ruby\gems\2.4.0\gems\review-2.5.0

何かと見ることも多いと思いますので覚えておきましょう。

=== VSCodeのインストール
インストールウィザードにしたがってポチポチインストールしましょう。
PATHの追加はデフォルトでチェックが入っていると思いますが、
そこだけ確認すれば大丈夫です。

インストールが完了したら、起動して次の拡張機能をインストールします。

 * Re:VIEW（vscode-language-review）
 * redpen-extension
 * prh - ProofReadingHelper

拡張機能のRe:VIEWは、VSCodeでRe:VIEWをサポートするための機能です。ややこしいですね。

redpenやprhは自動で校正を行ってくれる機能ですので、あわせて入れておきます。

=== 技術書テンプレートをフォークしてクローン
TechBoosterさんの熱いご厚意により、技術書テンプレートのリポジトリが公開されています。
本書もこのテンプレートを使用して執筆しました。

 * Re:VIEW-Templateリポジトリ
 ** https://github.com/TechBooster/ReVIEW-Template

感謝しながら自分のGitHubアカウントにフォークしてクローンしましょう。
スタイルやレイアウトの詳細は、「技術書をかこう！～はじめてのRe:VIEW～」（@<chap>{preface}参照）
およびリポジトリのドキュメントをご覧ください。

=== dvioptionsの修正
Re:VIEW-Templateはデフォルトでヒラギノフォントを使うようになっており、
Windowsでは通常ヒラギノフォントは入っていないのでPDFにコンパイルできません。
そこで、articlesフォルダにあるconfig.ymlのdvioptionsを修正します（@<list>{modify_dvi}）。

//listnum[modify_dvi][config.ymlの修正]{
# dvioptions: "-d 5"
　↓
dvioptions: "-f msmingoth.map -d 5"

# 游明朝及び游ゴシックを埋め込みたい場合は次のとおり
dvioptions: "-f yu-win10.map -d 5"
//}

Windows7で游明朝及び游ゴシックを使用する場合は、Microsoftが
游書体を配布しているのでそちらをインストールの上指定してください@<fn>{yu-win10}。
これでPDF出力時にMS明朝、MSゴシック、または游書体が埋め込まれます@<fn>{umekomi}。

//footnote[yu-win10][Micosoftダウンロードセンター https://www.microsoft.com/ja-jp/download/details.aspx?id=49116]
//footnote[umekomi][地味に本書は、Win7で書いて游書体を埋め込んでいます]

=== seqsplit.styの生成、配置
最後に、seqsplit.styを導入します。

冒頭で脇に置いてあったseqsplit.zipを解凍すると、
フォルダ内に「seqsplit.ins」があると思います。
ここでコマンドプロンプト（あるいはPowerShell）を開き、次のコマンドを実行します。

//cmd{
$ cd "解凍したフォルダに移動"
$ latex seqsplit.ins
//}

すると同じフォルダ内にseqsplit.styが出力されるので、
これをlatexフォルダに移動します。筆者の環境では次のところでした。

 * C:\w32tex\share\texmf-dist\tex\latex\seqsplit

seqsplitフォルダは自身で作成して、その中に移動してください。
これでやっとPDFコンパイルがとおるようになりました。

=== 動作確認
確認のために、articlesフォルダに次のファイルを生成します@<fn>{preface}。

 * preface.re

preface.reについて、VSCodeにて次のとおり記述します。
//listnum[test][preface.re]{
= はじめに
//}

VSCodeでターミナルを開いて（メニューバーの表示→ターミナル または Ctrl+@）、次のコマンドを実行します。

//cmd{
$ cd articles ← config.ymlが置いてあるフォルダに移動
$ review-pdfmaker config.yml
//}

しばらく待って「xxxx bytes written」と表示されたら成功です。
articlesフォルダにPDFが出力されているので確認してみてください。

//footnote[preface][なぜかReVIEW-Templateにはpreface.reだけ入ってない模様]

== まとめ
超突貫で執筆環境の構築とPDFコンパイルまで終わらせました。
TechBoosterさんのテンプレのおかげで、周辺環境を整えるのみで
執筆環境が整ってしまいました。
これで次回の技術書典では本が出せますね。

それではよき執筆ライフを！