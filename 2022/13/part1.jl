f = map(s->split(s, "\n")[1:2], split(open(io->read(io, String), "input"),"\n\n"))

println(f)