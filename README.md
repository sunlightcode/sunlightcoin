# SunlightCoin
SunlightChain is a public blockchain. Anyone can participate in the development of SunlightCoin. Simply download the SunlightCoin mining wallet and simply install it to experience the application of “blockchain” and “cryptocurrency” technologies.

SunlightChain 是公有区块链，任何人均可参与 SunlightCoin 的发展，只需下载 SunlightCoin 挖矿钱包，进行简单的安装，即可体验“区块链”和“加密货币”技术的应用，在实践中学习。

## How much is the STC value?
Gift currency activity: The mobile wallet is successfully installed, send screenshots and addresses, and immediately give 5000STC.

How much is the STC value? First, the wallet system developed by STC includes: Windows, Linux, MacOS, Android, IOS. The development language includes .NET, C, HTML5, Object C, Python, and the related research and development costs are related to these, and the blockchain technology learning cost is not included. In addition, STC has been operating stably for 39 weeks to generate 3E STC related electricity and equipment costs.
At present, the nodes are all over China, the United States, Canada, Japan, Germany, the United Kingdom, South Korea and other places.

STC 值多少钱，首先STC研发的钱包系统包含：Windows，Linux，MacOS，Android，IOS。开发语言包含.NET，C，HTML5，Object C，Python, 与这些相关的是对应的研发成本，还不包括区块链技术学习成本。再加上STC已经稳定运行39周共计产生3E枚STC相关电费及设备费用。
 目前节点遍布中国，美国，加拿大，日本，德国，英国，韩国等地。

## How to compile SunlightCoin
### Ubuntu 14.04
####下载源码
1. sudo apt-get update
2. apt-get install git
3. git clone https://gitee.com/sunlightcode/

####配置环境
1. sudo apt-get upgrade
2. sudo apt-get install make gcc g++
3. sudo apt-get install pkg-config
4. apt-get install libdb-dev libdb++-dev libboost-dev zlib1g-dev libssl-dev build-essential libminiupnpc-dev autoconf libevent-dev libzmq3-dev libqt5gui5 libqt5core5a libqt5dbus5 qttools5-dev qttools5-dev-tools libprotobuf-dev protobuf-compiler libqrencode-dev libtool libboost-all-dev

####编译代码
1. export CXXFLAGS=-std=c++11
2. ./autogen.sh
3. ./configure -without-gui --with-incompatible-bdb
4. make
5. make install

####运行服务
1. sunlightcoind  -conf=/mnt/.sunlightcoin/sunlightcoin.conf  -datadir=/mnt/.sunlightcoin/

