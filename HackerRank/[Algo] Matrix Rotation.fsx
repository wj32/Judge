match stdin.ReadLine().Split(' ') |> Array.map int with
| [|m; n; r|] ->
  let a =
    seq {1 .. m}
    |> Seq.map (fun _ -> stdin.ReadLine().Split(' ') |> Array.map int)
    |> Seq.toArray
  let b = Array.init m (fun i -> Array.zeroCreate n)
  
  for i = 0 to m - 1 do
    for j = 0 to n - 1 do
      let level = List.min [i; j; m - 1 - i; n - 1 - j]
      // (i,j) space constants
      let top = level
      let right = n - 1 - level
      let bottom = m - 1 - level
      let left = level
      // Level space constants
      let horizontalLength = n - 1 - level * 2
      let verticalLength = m - 1 - level * 2
      let topRight = horizontalLength
      let bottomRight = topRight + verticalLength
      let bottomLeft = bottomRight + horizontalLength
      let levelSize = bottomLeft + verticalLength
      
      let index =
        match i, j with
        | i, j when i = top -> j - left // Top
        | i, j when j = right -> topRight + (i - top) // Right
        | i, j when i = bottom -> bottomRight + (right - j) // Bottom
        | i, j when j = left -> bottomLeft + (bottom - i) // Left
        | _ -> failwith "Invalid coordinates"
      let index = (levelSize + (index - r) % levelSize) % levelSize
      let (i', j') =
        match index with
        | index when index < topRight -> (top, left + index) // Top
        | index when index < bottomRight -> (top + index - topRight, right) // Right
        | index when index < bottomLeft -> (bottom, right - (index - bottomRight)) // Bottom
        | index when index < levelSize -> (bottom - (index - bottomLeft), left) // Left
        | _ -> failwith "Invalid index in level"
      
      b.[i'].[j'] <- a.[i].[j]
  
  let join sep (strings : string seq) = System.String.Join(sep, strings)
  b
  |> Seq.map (fun row -> row |> Seq.map string |> join " ")
  |> join "\n"
  |> printfn "%s"
| _ ->
  failwith "Invalid input"
