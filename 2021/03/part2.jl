function f(a)
    zc = zeros(length(a[1])); oc = zeros(length(a[1]))
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
        if zc[j] == 1
            for x in a
                if reverse(x)[j] == 0
                    push!(b, x)
                else
                    push!(c, x)
                end
            end
            if length(b) == 1
                println(b[1])
                sleep(1)
            else
                f(b)
                println(length(b))
                sleep(1)
            end
        else
            for x in a
                if reverse(x)[j] == 1
                    push!(c, x)
                else
                    push!(b, x)
                end
            end
            if length(c) == 1
                println(c[1])
                sleep(1)
            else
                f(c)
                println(length(c))
                sleep(1)
            end
        end
    end
end

a = [parse.(Int, split(l, "")) for l in eachline("input")]
f(a)