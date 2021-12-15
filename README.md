# robotsystem

ロボットシステム学　課題1　リポジトリ

## 概要
---
今回のリポジトリは三つのLEDの点滅をスイッチによって点灯させるデバイスドライバで上田先生の作ったプログラムを改良したものです。  

---
## 動作環境
OS Ubuntu18.04 server  
Rasberry Pi 4B

---
## 必要なもの
Raspberry Pi 4B  
LED×3  
ブレッドボード×1  
ジャンパー線×6  
抵抗(330Ω)×3  

---
## 配線  
こちらは配線したものを上から撮った写真です。  
<img src="https://user-images.githubusercontent.com/95609545/146216787-3d2c212e-ff85-4998-afb6-1103f94a77ef.jpg" width="500">

簡単に説明するとGPIO25,24,23を使いLEDを点灯させる回路です。  
左から順番に25,24,23にLEDが連動している。  
回路自体は、GPIOからスイッチに入り出たほうをLEDのアノードに入れてカソードからでてそこから抵抗に入りグランドに落ちるというものでこれを三つ作りました。

---
## 動作方法  
### [インストールする]
以下のコマンドをディレクトリ内で実行してください。  
```
$ git clone https://github.com/Koutarou1123/robotsystem.git  
$ cd robotsystem  
$ make  
$sudo insmod myled.ko  
$sudo chmod 666 /dev/myled0  
```
---
### [アンインストールする]  
以下のコマンドをディレクトリ内で実行してください。  
```

$ sudo rmmod myled  
$ make clean  
```
## 実行方法
### LED1を点灯させたい場合
```
$ echo 1 > /dev/myled0
```
このコマンドLED1の回路に電流が流れる。  ずっと点灯するのではなく、スイッチを回路に加えたため自分がオンにしたい時だけスイッチを押すことで自由にオンオフが出来るようにした。これはLED1,2,3すべて同じである。  
### LED1を消灯させたい場合
```
$ echo 0 > /dev/myled0
```

### LED2を点灯させたい場合
```
echo 3 > /dev/myled0
```

### LED2を消灯させたい場合
```
$ echo 2 > /dev/myled0
```

### LED3を点灯させたい場合
```
echo 5 > /dev/myled0
```

###  LED3を消灯させたい場合
```
echo 4 > /dev/myled0
```

## 実行結果
以下のリンクから今回の動画がyoutubeで見ることが可能です
http://youtube.be/xy1


## ライセンス
GNU General Public License v3.0  
ライセンスの中身の詳細が見たい場合はリポジトリ内にあるCOPYINGを参照してください。
