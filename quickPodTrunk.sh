
version="0.1.6"
git tag -d $version && git push --delete origin $version && git tag $version && git push --tags