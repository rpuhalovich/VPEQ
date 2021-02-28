curl -O "https://aspikplugins.com/downloads/AU_SDK.zip"
unzip AU_SDK.zip
mv AU_SDK/AU_SDK AU
rm -rf __MACOSX
rm AU_SDK.zip

git clone --recursive https://github.com/steinbergmedia/vst3sdk.git VST_SDK/VST3_SDK
rm -rf VST_SDK/VST3_SDK/.git

# It's beyond me why the github repo and the official download are different...
mv VST_SDK/VST3_SDK/doc VST_SDK/VST3_SDK/vst3_doc