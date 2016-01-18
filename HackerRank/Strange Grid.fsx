match stdin.ReadLine().Split(' ') |> Array.map int64 with
| [|r; c|] ->
  printfn "%d" ((r - 1L) / 2L * 10L + (r - 1L) % 2L + (c - 1L) * 2L)
| _ ->
  failwith "Invalid input"
