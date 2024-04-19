using Intervals
f = open("input", "r")
start = Vector{Interval{Closed, Closed}}()
m = split(match(r"\S+(.*)", readline(f))[1], " ")
