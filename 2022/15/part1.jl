rx = r".{12}(-?\d+).{4}(-?\d+).{25}(-?\d+).{4}(-?\d+)"

for l in eachline(open("input", "r"))
    p1, p2 = [parse.(Int, match(rx, l))]
end