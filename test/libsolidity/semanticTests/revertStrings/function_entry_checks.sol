contract C {
    function t(uint) public pure {}
}
// ====
// EVMVersion: >=byzantium
// compileViaYul: true
// revertStrings: debug
// ----
// t(uint256) -> FAILURE, hex"08c379a0", 0x20, 40, "ABI decoding error: tuple data t", "oo short"
