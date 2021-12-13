import msalign as m

def align(query, subject):
    return m.NeedlemanWunsch(query, subject).get_alignment()

# base cases
assert align(query="", subject="") == ""
assert align(query="MMM", subject="") == ""
assert align(query="", subject="MMM") == "---"

assert align(query="M", subject="M") == "M"
assert align(query="M", subject="MMM") == "--M"
assert align(query="WM", subject="WMMM") == "WM--"

assert align(query="WMAM", subject="WMMM") == "WMAM"

assert align("ATTTTY", "ATTTT-IT") == "ATTTT--Y"
assert align("ATTTTY", "ATTTT--IT") == "ATTTT---Y"
