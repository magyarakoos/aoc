# Experimental!
Input ← &fras "input"
Input ← ⊜(□⊜□⊸≠@\n)¬⊸⦷"\n\n" Input

Graph ← map◇⍚(
  °$"_{_}"
  ⊙(
    °/$"_,_"
    ⍜⊣(□$"x>0:_")
    ⍚(□₄ ˜⊗"xmas" ⊓∩⊢⋕ °$"___:_")
  )
) ⊢
StartP₁ ← ◇≡◇(⊜⋕⊸∊+@0⇡10) ⊣
StartP₂ ← ¤□₂"in" ↯4 1_4e3

Next ← (
  ∩°□ 𝄐⌟get°⊟
  ∧(°□₄°□
    ⊓:⤙⊙⊙◌
    ⨬(⊃⍜⊡⍜⊣↧⍜⊡(⍜⊢↥⊙+₁)
    | ⊃⍜⊡⍜⊢↥⍜⊡(⍜⊣↧⊙-₁)
    ) =@<
    ⊙˜□₂
  )
)
Step ← ⊂⊃(/◇⊂⍚⌟Next ▽|▽¬) ≠□"A"⊸≡⊢ ▽≠□"R"⊸≡⊢
Calc ← ≡(°□⊣) ⍥(Step)∞ StartP₂ Graph

P₁ ← ⧻⊚ ▽/↥⊸⊞(/↧⊂≡(⊓⌟≥≤°⊟)) ⊃Calc StartP₁
P₂ ← /+≡(/×+₁≡/-) Calc

⊃P₂P₁ Input
