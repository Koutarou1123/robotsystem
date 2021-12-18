# robotsystem
ロボットシステム学　課題1　リポジトリ  
## 概要
---
今回のリポジトリは先生が授業でやっていた一つのLED点灯に加え三つのLED、LED1,LED2,LED3の点滅を行うものです。
 
---
## 動作環境
・OS Ubuntu18.04 server  
・Rasberry Pi 4B

---
## 必要なもの
・Raspberry Pi 4B  
・LED×3  
・ブレッドボード×1  
・ジャンパー線×6  
・抵抗(330Ω)×3  

---
## 配線  
こちらは配線したものを上から撮った写真です。  
<img src="https://user-images.githubusercontent.com/95609545/146643532-c4cb33cd-e520-487e-a949-f396b8e260f7.jpg" width="500">  
簡単に説明するとGPIO25を使いLED1を点灯させることが出来、またGPIO25,24,23でLED1,LED2,LED3を点滅させることが出来るようにしました。  
回路自体は、GPIOからスイッチに入り出たほうをLEDのアノードに入れてカソードからでてそこから抵抗に入りグランドに落ちるというものでこれを三つ作りました。

---
## 動作方法  
### [インストールする]
以下のコマンドをディレクトリ内で実行してください。  
```
$ git clone https://github.com/Koutarou1123/robotsystem.git  
$ cd robotsystem  
$ make  
$ sudo insmod myled.ko  
$ sudo chmod 666 /dev/myled0  
```  
### [アンインストールする]  
以下のコマンドをディレクトリ内で実行してください。  
```
$ sudo rmmod myled  
$ make clean  
```
---
## 実行方法
### LED1を点灯させたい場合
```
$ echo 1 > /dev/myled0
```
このコマンドLED1の回路に電流が流れる。ずっと点灯するのではなく、スイッチを回路に加えたため自分がオンにしたい時だけスイッチを押すことで自由にオンオフが出来るようにした。これはLED1,2,3すべて同じである。  
### LED1を消灯させたい場合
```
$ echo 0 > /dev/myled0
```  
### LED1を点滅させたい場合
```
$ echo 2 > /dev/myled0
```  
### LED2を点滅させたい場合
```
$ echo 3 > /dev/myled0
```  
### LED3を点滅させたい場合
```
$ echo 3 > /dev/myled0
```  
## 実行結果
以下のリンクから今回の動画がyoutubeで見ることが可能です。  
  https://youtu.be/dXnT84SvqHs
## ライセンス
GNU General Public License v3.0  
ライセンスの詳細が見たい場合はリポジトリ内にあるCOPYINGを参照してください。

## 著作
Ryuichi Ueda  
Yuma Ito  
### コントリビューション  
授業通りにソースコードを作成しLEDを一つ点灯・消灯させることに成功しました。  
なので、発展の内容としてLED三つをスイッチでON,OFFしようとしたがうまくいかなかったです。  
そこで、上記のYuma ItoにどのようにしてLEDを追加するかを教わりプログラムを変更し目的であるスイッチでのLEDのON,OFFに成功することができました。
しかし、それではコードがほとんど同じになってしまうため1からプログラムを書き換えLEDの点滅をできるようにした。


