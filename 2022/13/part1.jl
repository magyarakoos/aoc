f = map(s->split(s, "\n")[1:2], split(open(io->read(io, String), "input"),"\n\n"))
for p in f
    a = p[1]; b = p[2]
    println(a)
    println(b)
    println()
end