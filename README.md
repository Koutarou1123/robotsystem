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
https://github.com/Koutarou1123/robotsystem/blob/main/%E3%83%AD%E3%83%9C%E3%82%B7%E3%82%B9%E5%86%99%E7%9C%9F.jpg

簡単に説明するとGPIO25,24,23を使いLEDを点灯させる回路です。  
左から順番に25,24,23にLEDが連動している。  
回路自体は、GPIOからスイッチに入り出たほうをLEDのアノードに入れてカソードからでてそこから抵抗に入りグランドに落ちるというものでこれを三つ作りました。

---
## 動作方法  
### [インストールする]
以下のコマンドをディレクトリ内で実行してください。  

$ git clone https://github.com/Koutarou1123/robotsystem.git  
$ cd robotsystem  
$ make  
$sudo insmod myled.ko  
$sudo chmod 666 /dev/myled0  

---




