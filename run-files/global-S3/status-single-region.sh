#!/usr/bin/env bash
set -u
shopt -s nullglob  # so unmatched globs expand to nothing instead of a literal

i=1
# --- count model output lines (x) across all matching files for this region ---
files=( "region-$i"/var-out/NPP* )
if ((${#files[@]})); then
  x=$(cat "${files[@]}" | wc -l)
else
  x=0
fi

# --- compute target lines (y) from the CSV's line count * 325 ---
csv="/group/moniergrp/TRENDY/input-files/region-input/S3/region-$i/lulcc-TRENDY-1700-2024.csv"
if [[ -f "$csv" ]]; then
  y=$(wc -l < "$csv")
else
  y=0
fi

# --- report ---
if (( y > 0 && x == y )); then
  printf "Region %d is complete (%d/%d lines).\n" "$i" "$x" "$y"
elif (( y > 0 )); then
  pct=$(awk -v x="$x" -v y="$y" 'BEGIN{printf("%.1f", (x/y)*100)}')
  printf "Region %d is %s%% complete (%d/%d lines).\n" "$i" "$pct" "$x" "$y"
else
  printf "Region %d: target is 0 lines (check input). We have %d lines.\n" "$i" "$x"
fi

