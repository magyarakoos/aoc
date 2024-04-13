∆(a, b) = abs(a[1] - b[1]) + abs(a[2] - b[2])
const rx = r".{12}(-?\d+).{4}(-?\d+).{25}(-?\d+).{4}(-?\d+)"
const y::Int = 10
s = Set(); beacons = Set();
for l in eachline(open("input", "r"))
    m = [parse.(Int, match(rx, l)[i]) for i in 1:4]
    ps = (m[1], m[2]); pb = (m[3], m[4])
    push!(beacons, pb)
    if (∆(ps, (ps[1], y)) > ∆(ps, pb))
        continue
    end
    d = ∆(ps, pb)
    for x in (ps[1] - d):(ps[1] + d)
        if (∆(ps, (x, y)) <= d)
            push!(s, (x, y))
        end
    end
end0
println(length(setdiff(s, beacons)))