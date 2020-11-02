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
            checksum: "d22becd28e56c4653004605cbd4b726a4f86fd78588c1113e6c86498d9a935f3"
        ),
        .binaryTarget(
            name: "kpathsea",
            url: "https://github.com/holzschu/lib-tex/releases/download/1.0/kpathsea.xcframework.zip",
            checksum: "a5074f20ad8500e324655692e35c35872b3429b557e58a1c311f0098857522d7"
        ),
        .binaryTarget(
            name: "luatex",
            url: "https://github.com/holzschu/lib-tex/releases/download/1.0/luatex.xcframework.zip",
            checksum: "d2698c3b9b1390771d9b5eca17a5254d9ac68155208673eccb96e07f65bf1e91"
        ),
        .binaryTarget(
            name: "pdftex",
            url: "https://github.com/holzschu/lib-tex/releases/download/1.0/pdftex.xcframework.zip",
            checksum: "546b2cc2be8ea55928f59e372749e1927ef91e277538847f4f873437cca5a8ec"
        ),
        .binaryTarget(
            name: "bibtex",
            url: "https://github.com/holzschu/lib-tex/releases/download/1.0/bibtex.xcframework.zip",
            checksum: "aaf5273926947edb18fc32d7d8fc93badc4fa1bafd35533f390b9e8dca728076"
        )
    ]
)
