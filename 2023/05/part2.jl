using Intervals
f = open("input", "r")
start = Vector{Interval{Closed, Closed}}()
m = map(x -> parse(Int, x), split(match(r"\S+(.*)", readline(f))[1]))

for i in 1:10: