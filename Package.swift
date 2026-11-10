
// swift-tools-version: 6.0
// The swift-tools-version declares the minimum version of Swift required to build this package.

import PackageDescription

let package = Package(
    name: "SifliReaderOCSDK",
    platforms: [
        .iOS(.v12),
        .macOS(.v10_15)
    ],
    products: [
        .library(
            name: "SifliReaderOCSDK",
            targets: ["SifliReaderOCSDK"]),
    ],

    targets: [
        .binaryTarget(
            name: "SifliReaderOCSDK",
            path: "Sources/SifliReaderOCSDK/SifliReaderOCSDK.xcframework"
        )
    ]
)


