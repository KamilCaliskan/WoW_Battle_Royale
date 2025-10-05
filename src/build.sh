if [ -f "battle_royale" ]; then
    echo "✓ Build successful!"
    echo "=== Running Program ==="
    ./battle_royale
else
    echo "✗ Build failed"
fi
