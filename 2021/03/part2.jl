function f(a)
    for j in eachindex(a[1]), i in eachindex(a)
        if (a[i][j] == 1) global oc[j] += 1
        else global zc[j] += 1 end
    end
    for j in eachindex(zc)
        zc[j] = zc[j] <= oc[j] ? 0 : 1
    end
    reverse!(zc)
    b = []; c = []
    for j in eachindex(zc)
        if zc[j]
            for x in a
                if x & (1 << (j - 1)) == 0
                    push!(b, x)
                else
                    push!(c, x)
                end
            end
            if length(b) == 1
        else
            for x in a
                if x & (1 << (j - 1)) == 0
                    push!(c, x)
                else
                    push!(b, x)
                end
            end
        end
    end
end

a = [parse.(Int, split(l, "")) for l in eachline("input")]
zc = zeros(length(a[1])); oc = zeros(length(a[1]))
println(g * e)