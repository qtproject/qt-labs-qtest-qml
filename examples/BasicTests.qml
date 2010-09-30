import Qt 4.7
import QtTest 1.0

TestCase {
    name: "BasicTests"

    function test_pass() {
        compare(2 + 2, 4, "2 + 2")
    }

    function test_fail() {
        compare(2 + 2, 5, "2 + 2")
    }

    function test_skip() {
        skip("skipping")
    }

    function test_expecting() {
        expectFail("this is the fail we wanted")
        verify(false)
    }

    function test_table_data() {
        return [
            {tag: "2 + 2 = 4", a: 2, b: 2, answer: 4 },
            {tag: "2 + 6 = 8", a: 2, b: 6, answer: 8 },
            {tag: "2 + 2 = 5", a: 2, b: 2, answer: 5 }, // fail
        ]
    }

    function test_table(data) {
        compare(data.a + data.b, data.answer)
    }
}
