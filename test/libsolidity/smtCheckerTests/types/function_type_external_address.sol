pragma experimental SMTChecker;
contract C {
    function f(address a, function(uint) external g) public pure {
		address b = g.address;
		assert(a == b);
    }
}
// ----
// Warning: (126-135): Assertion checker does not yet support this expression.
// Warning: (139-153): Assertion violation happens here
