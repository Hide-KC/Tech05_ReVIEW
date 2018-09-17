= Re:VIEW環境を構築するぞ！
執筆環境の構築手順です。
第１章とかついていますが、本章しかないのであしからずなのです。

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

== 構築開始
=== Rubyのインストール
Re:VIEWリポジトリのdoc/quickstart.ja.mdを見ると、次のように記載されています。

//quote{
Re:VIEWはRuby言語で記述されており、Linux/Unix互換システムで動作します。
Mac OS XおよびWindows Cygwinでも動作可能です。
Ruby gemあるいはGitのいずれかを使ってダウンロード・展開します。
//}

ということで、Rubyをインストールします。

ダウンロードしたRubyInstallerをポチポチ押していって、
黒い画面が出てきたら1,2,3を順番にすべて実行していきます。

//image[ruby_install][黒い画面になったら１～３を順番に実行]{
//}

ネットからどんどこファイルをダウンロードするので気長に待ちます。
インストールが終わったら、念のためちゃんと出来ているか確認します。
コマンドプロンプトまたはPowerShellを起動して次のコマンドを打ちます。

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

//image[download_server][サーバを選択する]{
//}

サーバの調子によってはダウンロードがうまくいかない場合があります。
もしダウンロードできないようでしたら別のサーバを選択するか、
時間を置いてやり直してみてください。

そのあとは「次へ」または「OK」をポチっていきます@<fn>{kakure}。
最後に次のように表示されれば成功です（@<img>{success_tex}）。

//image[success_tex][TeXインストールの完了]{
//}

//footnote[kakure][途中、小さい画面が他の画面の後ろに隠れてしまうかもしれません。焦らず…。]

=== Git for Windowsのインストール
VSCodeではバージョン管理にGit for Windowsを使用します。
もしmsys2版Gitを使いたい場合（開発環境と競合する等）、msys2版Gitは
「git rev-parse --show-toplevelを実行すると、/から始まるPOSIXシェル環境のパスを返します」@<fn>{msys2_git}
ので回避策が必要になります。
本書ではストレートにGit for Windowsを使用します。

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
インストールウィザードに従ってポチポチインストールしましょう。
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
スタイルやレイアウトの詳細は「技術書をかこう！～はじめてのRe:VIEW～」（@<chap>{preface}参照）
およびリポジトリのドキュメントをご覧ください。

=== dvioptionsの修正
Re:VIEW-TemplateはデフォルトでMacのヒラギノを使うようになっており、このままではPDFにコンパイルできませんので、
articlesフォルダにあるconfig.ymlのdvioptionsを修正します（@<img>{modify_dvi}）。

//image[modify_dvi][config.ymlの修正]{
# dvioptions: "-d 5"
　↓
dvioptions: "-f msmingoth.map -d 5"
//}

これでPDF出力時にMS明朝、MSゴシックが埋め込まれます。

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
これを次の場所に移動します。

 * C:\w32tex\share\texmf-dist\tex\latex\seqsplit

seqsplitフォルダは自身で作ってその中に移動してください。
これでやっとPDFコンパイルができるようになりました。

=== 動作確認
確認のために、articlesフォルダに次のファイルを生成します@<fn>{preface}。

 * preface.re

preface.reについて、VSCodeにて次のとおり記述します。
//listnum[test][各ファイルへの記載]{
= はじめに
//}

VSCodeでターミナルを開いて（メニューバーの表示→ターミナル または Ctrl+@）、次のコマンドを実行します。

//cmd{
$ cd articles
$ review-pdfmaker config.yml
//}

しばらく待って「xxxx bytes written」と表示されたら成功です。
articlesフォルダにPDFが出力されているので確認してみてください。

なおpreface.reを作れば出力できるはずですが、もしかしたらエラー出ちゃうかもしれません。
そしたらすみません、ググってみてください。

//footnote[preface][なぜかReVIEW-Templateにはpreface.reだけ入ってない模様。]

== まとめ
超突貫で執筆環境の構築とPDFコンパイルまで終わらせました。
TechBoosterさんのテンプレのおかげで、周辺環境を整えるのみで
執筆環境が整ってしまいました。

それではよき執筆ライフを！