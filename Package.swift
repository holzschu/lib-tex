// swift-tools-version:5.3

import PackageDescription

let package = Package(
    name: "texlive",
    products: [
        .library(name: "texlive", targets: ["texlua53", "kpathsea", "luatex", "pdftex", "bibtex"])
    ],
    dependencies: [
    ],
    targets: [
        .binaryTarget(
            name: "texlua53",
            url: "https://github.com/holzschu/lib-tex/releases/download/1.0/texlua53.xcframework.zip",
            checksum: "62e34069ddef84a02f3c211aa0ab8165da13bcc27b71d0293442fc6722f3f301"
        ),
        .binaryTarget(
            name: "kpathsea",
            url: "https://github.com/holzschu/lib-tex/releases/download/1.0/kpathsea.xcframework.zip",
            checksum: "5579e3067857663fa73527fb0eeba86d92cd10767a051cfd3ad132405a72ac94"
        ),
        .binaryTarget(
            name: "luatex",
            url: "https://github.com/holzschu/lib-tex/releases/download/1.0/luatex.xcframework.zip",
            checksum: "1598bea608ad7b54316d2cba69b954bc8bb2a41887b0c9c7634811047ca36d56"
        ),
        .binaryTarget(
            name: "pdftex",
            url: "https://github.com/holzschu/lib-tex/releases/download/1.0/pdftex.xcframework.zip",
            checksum: "c0724610fde95686d0842400473dd6f7cc55d943b545ceb7a6de2bb2473024bf"
        ),
        .binaryTarget(
            name: "bibtex",
            url: "https://github.com/holzschu/lib-tex/releases/download/1.0/bibtex.xcframework.zip",
            checksum: "a8711eab1c058ca04363617405cceb48be1fbf936dd6b83028898b6ff183194c"
        )
    ]
)
