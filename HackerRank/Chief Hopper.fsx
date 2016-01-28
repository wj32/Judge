let n = stdin.ReadLine()
stdin.ReadLine().Split(' ')
|> Array.rev
|> Seq.fold
  (fun (acc, underflow) h ->
    let acc' = (acc + float h) / 2.
    // HACK
    let fractional = acc - floor acc
    let fractional' = acc' - floor acc'
    (acc', underflow || (0. < fractional && fractional < 0.01 && fractional' = 0.)))
  (0., false)
|> (fun (acc, underflow) -> acc + (if underflow then 1. else 0.))
|> ceil
|> int
|> printfn "%d"
