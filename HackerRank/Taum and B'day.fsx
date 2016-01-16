for _ in {1 .. stdin.ReadLine() |> int} do
  match [0; 1] |> Seq.map (fun _ -> stdin.ReadLine().Split(' ')) |> Array.concat |> Array.map int64 with
  | [|b; w; x; y; z|] ->
    printfn "%d" (b * (min x (y + z)) + w * (min y (x + z)))
  | _ -> failwith "Invalid input"
