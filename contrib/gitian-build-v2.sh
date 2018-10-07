# Copyright (c) 2018 The OBSR Core developers
# Distributed under the MIT software license, see the accompanying
# file COPYING or http://www.opensource.org/licenses/mit-license.php.

#git clone git@github.com/observerdev/gitian.sigs.git
#git clone git@github.com/observerdev/obsr-detached-sigs.git
#git clone git@github.com/devrandom/gitian-builder.git

rm -fR ./obsr
git clone git@github.com:observernet/obsr.git

cd ./obsr
export SIGNER="${1}"
export VERSION="${2}"
git fetch
git checkout v${VERSION}
cd ..

cd ./gitian.sigs
git pull
cd ..

cd ./gitian-builder
git pull
cd ..

mkdir -p ./obsr-release-binaries/obsr-v${VERSION}/debug

cd ./gitian-builder
./bin/gbuild --num-make 2 --memory 3000 --commit obsr=v${VERSION} ../obsr/contrib/gitian-descriptors/gitian-linux.yml
./bin/gsign --signer "$SIGNER" --release ${VERSION}-linux --destination ../gitian.sigs/ ../obsr/contrib/gitian-descriptors/gitian-linux.yml
mv build/out/obsr-*.tar.gz build/out/src/obsr-*.tar.gz ../

./bin/gbuild --num-make 2 --memory 3000 --commit obsr=v${VERSION} ../obsr/contrib/gitian-descriptors/gitian-win.yml
./bin/gsign --signer "$SIGNER" --release ${VERSION}-win-unsigned --destination ../gitian.sigs/ ../obsr/contrib/gitian-descriptors/gitian-win.yml
mv build/out/obsr-*-win-unsigned.tar.gz inputs/obsr-win-unsigned.tar.gz
mv build/out/obsr-*.zip build/out/obsr-*.exe ../

./bin/gbuild --num-make 2 --memory 3000 --commit obsr=v${VERSION} ../obsr/contrib/gitian-descriptors/gitian-osx.yml
./bin/gsign --signer "$SIGNER" --release ${VERSION}-osx-unsigned --destination ../gitian.sigs/ ../obsr/contrib/gitian-descriptors/gitian-osx.yml
mv build/out/obsr-*-osx-unsigned.tar.gz inputs/obsr-osx-unsigned.tar.gz
mv build/out/obsr-*.tar.gz build/out/obsr-*.dmg ../

./bin/gbuild --num-make 2 --memory 3000 --commit obsr=v${VERSION} ../obsr/contrib/gitian-descriptors/gitian-aarch64.yml
./bin/gsign --signer "$SIGNER" --release ${VERSION}-linux --destination ../gitian.sigs/ ../obsr/contrib/gitian-descriptors/gitian-aarch64.yml
mv build/out/obsr-*.tar.gz build/out/src/obsr-*.tar.gz ../
cd ..

cd ./gitian-builder
./bin/gverify -v -d ../gitian.sigs/ -r ${VERSION}-linux ../obsr/contrib/gitian-descriptors/gitian-linux.yml
./bin/gverify -v -d ../gitian.sigs/ -r ${VERSION}-win-unsigned ../obsr/contrib/gitian-descriptors/gitian-win.yml
./bin/gverify -v -d ../gitian.sigs/ -r ${VERSION}-osx-unsigned ../obsr/contrib/gitian-descriptors/gitian-osx.yml
cd ..

cd ./gitian.sigs
git add ${VERSION}-linux/"${SIGNER}"
git add ${VERSION}-win-unsigned/"${SIGNER}"
git add ${VERSION}-osx-unsigned/"${SIGNER}"
git commit -S -m "Add ${VERSION} unsigned sigs for ${SIGNER}"
git push  # Assuming you can push to the gitian.sigs tree
cd ..

mv ./obsr-*debug*.tar.gz ./obsr-release-binaries/obsr-v${VERSION}/debug/
mv ./obsr-*debug*.zip ./obsr-release-binaries/obsr-v${VERSION}/debug/
mv ./obsr-*.tar.gz ./obsr-release-binaries/obsr-v${VERSION}/
mv ./obsr-*.zip ./obsr-release-binaries/obsr-v${VERSION}/
mv ./obsr-*.exe ./obsr-release-binaries/obsr-v${VERSION}/
mv ./obsr-*.dmg ./obsr-release-binaries/obsr-v${VERSION}/

cd ./obsr-release-binaries/obsr-v${VERSION}/
gpg --digest-algo sha256 --default-key 0x${SIGNER} --clearsign SHA256SUMS # outputs SHA256SUMS.asc
rm SHA256SUMS
cd ..;cd ..;