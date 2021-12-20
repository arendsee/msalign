#!/usr/bin/env python3

import unittest
import msalign as m

def align(query, subject):
    return m.NeedlemanWunsch(query, subject).get_alignment()

class TestAlignments(unittest.TestCase):

    def test_base_cases(self):
        self.assertEqual(align(query="", subject=""), "")
        self.assertEqual(align(query="CAT", subject=""), "")
        self.assertEqual(align(query="", subject="CAT"), "---")

    def test_simple(self):
        self.assertEqual(align(query="M", subject="M"), "M")
        self.assertEqual(align(query="M", subject="MMM"), "M--")
        self.assertEqual(align(query="WM", subject="WMMM"), "WM--")
        self.assertEqual(align(query="WMAM", subject="WMMM"), "WMAM")

    def test_problematic(self):
        self.assertEqual(align(query="ATTTTY", subject="ATTTT-IT"), "ATTTTY--")
        self.assertEqual(align(query="ATTTTY", subject="ATTTT--IT"), "ATTTTY---")

    def test_gaps(self):
        self.assertEqual(align(query="TTTW", subject="T--TTW"), "T-TTTW")
        self.assertEqual(align(query="GANDALF", subject="GANDALFFANEALF"), "GANDALF-------")
        self.assertEqual(align(query="GANDALF", subject="FANEALFGANDALF"), "-------GANDALF")
        self.assertEqual(align(query="GANDALF", subject="GGANDALFF"), "-GANDALF-")
        self.assertEqual(align(query="GANDALF", subject="GAGANDALFLF"), "--GANDALF--")

    def test_errors(self):
        with self.assertRaises(ValueError):
            align(query="CAT-IN-HAT", subject="CAT")

        with self.assertRaises(ValueError):
            align(query="BONE", subject="CAT")

        with self.assertRaises(ValueError):
            align(query="CAT", subject="BONE")

if __name__ == '__main__':
    unittest.main()
