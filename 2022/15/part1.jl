using IntervalSets

∆(a, b) = abs(a[1] - b[1]) + abs(a[2] - b[2])
∩(a, b) = !isempty(intersect(Interval(a[1], a[2]), Interval(b[1], b[2])))

function merge(intvs)
    intvs2 = []
    for intv in intvs
        i = 1
        while i <= length(intvs2)
            if ∩(intvs2[i], intv)
                intvs2[i] = (
                    min(intvs2[i][1], intv[1]), 
                    max(intvs2[i][2], intv[2])
                )
                break
            end
            i += 1
        end
        if i > length(intvs2)
            push!(intvs2, intv)
        end
    end
    if (length(intvs) == length(intvs2))
        return intvs2
    end
    merge(intvs2)
end

const rx = r".{12}(-?\d+).{4}(-?\d+).{25}(-?\d+).{4}(-?\d+)"
const y::Int = 2e6
intvs = []; beacons = Set()

for l in eachline(open("input", "r"))
    m = [parse.(Int, match(rx, l)[i]) for i in 1:4]
    ps = (m[1], m[2]); pb = (m[3], m[4])
    if pb[2] == y
        push!(beacons, pb[1])
    end
    d = ∆(ps, pb) - ∆(ps, (ps[1], y))
    if (d >= 0)
        push!(intvs, (ps[1] - d, ps[1] + d))
    end
end
intv = merge(intvs)[1]
dec = 0
for x in beacons
    if intv[1] <= x && x <= intv[2]
        global dec -= 1
    end
end
println(intv[2] - intv[1] + 1 - dec)