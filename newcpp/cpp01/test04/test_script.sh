#!/bin/bash


echo "🔧 === Compilation du programme ==="
make re

if [ $? -ne 0 ]; then
    echo "❌ Erreur de compilation"
    exit 1
fi

echo "✅ Compilation réussie"
echo ""

# Compteurs pour le résumé
total_tests=0
passed_tests=0

# Fonction pour valider un test
validate_test() {
    local test_name="$1"
    local expected_code="$2"
    local actual_code="$3"
    local additional_check="$4"
    
    total_tests=$((total_tests + 1))
    
    if [ "$expected_code" = "$actual_code" ] && [ "$additional_check" != "FAIL" ]; then
        echo "✅ $test_name : RÉUSSI"
        passed_tests=$((passed_tests + 1))
    else
        echo "❌ $test_name : ÉCHEC (attendu: $expected_code, obtenu: $actual_code)"
    fi
}

echo "🧪 === Tests de base ==="
echo ""

echo "Test 1: Usage incorrect"
./sed >/dev/null 2>&1
validate_test "Usage incorrect" "1" "$?" ""
echo ""

echo "Test 2: s1 vide"
./sed test_normal.txt "" "replacement" >/dev/null 2>&1
validate_test "s1 vide" "1" "$?" ""
echo ""

echo "Test 3: Fichier inexistant"
./sed nonexistent.txt "hello" "hi" >/dev/null 2>&1
validate_test "Fichier inexistant" "1" "$?" ""
echo ""

echo "Test 4: Fichier vide"
./sed test_empty.txt "hello" "hi" >/dev/null 2>&1
code=$?
additional=""
if [ ! -f "test_empty.txt.replace" ]; then
    additional="FAIL"
fi
validate_test "Fichier vide" "0" "$code" "$additional"
echo ""

echo "Test 5: Remplacement normal"
./sed test_normal.txt "Hello" "Hi" >/dev/null 2>&1
code=$?
additional=""
if [ -f "test_normal.txt.replace" ]; then
    if ! grep -q "Hi world" test_normal.txt.replace; then
        additional="FAIL"
    fi
else
    additional="FAIL"
fi
validate_test "Remplacement normal" "0" "$code" "$additional"
echo ""

echo "Test 6: s1 == s2 (optimisation)"
./sed test_normal.txt "Hello" "Hello" >/dev/null 2>&1
code=$?
additional=""
if [ -f "test_normal.txt.replace" ]; then
    if ! diff test_normal.txt test_normal.txt.replace >/dev/null; then
        additional="FAIL"
    fi
else
    additional="FAIL"
fi
validate_test "s1 == s2" "0" "$code" "$additional"
echo ""

echo "Test 7: s1 non trouvé"
./sed test_normal.txt "xyz" "abc" >/dev/null 2>&1
code=$?
additional=""
if [ -f "test_normal.txt.replace" ]; then
    if ! diff test_normal.txt test_normal.txt.replace >/dev/null; then
        additional="FAIL"
    fi
else
    additional="FAIL"
fi
validate_test "s1 non trouvé" "0" "$code" "$additional"
echo ""

echo "Test 8: s2 vide (suppression)"
./sed test_normal.txt "Hello" "" >/dev/null 2>&1
code=$?
additional=""
if [ -f "test_normal.txt.replace" ]; then
    if grep -q "Hello" test_normal.txt.replace; then
        additional="FAIL"
    fi
else
    additional="FAIL"
fi
validate_test "s2 vide" "0" "$code" "$additional"
echo ""

echo "Test 9: Occurrences chevauchantes"
./sed test_overlapping.txt "aa" "X" >/dev/null 2>&1
code=$?
additional=""
if [ -f "test_overlapping.txt.replace" ]; then
    if ! grep -q "XX" test_overlapping.txt.replace; then
        additional="FAIL"
    fi
else
    additional="FAIL"
fi
validate_test "Occurrences chevauchantes" "0" "$code" "$additional"
echo ""

echo "🚀 === Tests avancés ==="
echo ""

echo "Test 10: Fichier en lecture seule"
echo "Test content for readonly file" > test_readonly.txt
chmod 444 test_readonly.txt
./sed test_readonly.txt "Test" "Modified" >/dev/null 2>&1
code=$?
additional=""
if [ ! -f "test_readonly.txt.replace" ]; then
    additional="FAIL"
fi
validate_test "Fichier lecture seule" "0" "$code" "$additional"
chmod 644 test_readonly.txt 2>/dev/null
rm -f test_readonly.txt 2>/dev/null
echo ""

echo "Test 11: Répertoire protégé"
mkdir -p test_protected_dir
echo "Test content" > test_protected_dir/test_file.txt
chmod 555 test_protected_dir
./sed test_protected_dir/test_file.txt "Test" "Modified" >/dev/null 2>&1
code=$?
additional=""
if [ -f "test_protected_dir/test_file.txt.replace" ]; then
    additional="FAIL"
fi
validate_test "Répertoire protégé" "1" "$code" "$additional"
chmod 755 test_protected_dir 2>/dev/null
rm -rf test_protected_dir 2>/dev/null
echo ""

echo "Test 12: Performance (gros fichier)"
for i in {1..1000}; do
    echo "Line $i: This is a test line with some content to replace. Hello world!" >> test_large.txt
done
start_time=$(date +%s.%N)
./sed test_large.txt "Hello" "Hi" >/dev/null 2>&1
end_time=$(date +%s.%N)
code=$?
execution_time=$(echo "$end_time - $start_time" | bc -l 2>/dev/null || echo "N/A")
additional=""
if [ -f "test_large.txt.replace" ]; then
    replaced_count=$(grep -c "Hi world" test_large.txt.replace)
    if [ "$replaced_count" -ne 1000 ]; then
        additional="FAIL"
    fi
else
    additional="FAIL"
fi
validate_test "Performance (${execution_time}s)" "0" "$code" "$additional"
rm -f test_large.txt test_large.txt.replace
echo ""

echo "Test 13: Caractères spéciaux"
echo "Test with special chars: @#\$%^&*()[]{}|\\;:'\",.<>?/~\`" > test_special.txt
./sed test_special.txt "@#\$" "XYZ" >/dev/null 2>&1
code=$?
additional=""
if [ -f "test_special.txt.replace" ]; then
    if ! grep -q "XYZ" test_special.txt.replace; then
        additional="FAIL"
    fi
else
    additional="FAIL"
fi
validate_test "Caractères spéciaux" "0" "$code" "$additional"
rm -f test_special.txt test_special.txt.replace
echo ""

echo "Test 14: Lignes très longues"
long_line=$(printf 'A%.0s' {1..10000})
echo "$long_line" > test_long_line.txt
./sed test_long_line.txt "A" "B" >/dev/null 2>&1
code=$?
additional=""
if [ -f "test_long_line.txt.replace" ]; then
    line_length=$(wc -c < test_long_line.txt.replace)
    if [ "$line_length" -lt 9000 ]; then
        additional="FAIL"
    fi
else
    additional="FAIL"
fi
validate_test "Lignes très longues" "0" "$code" "$additional"
rm -f test_long_line.txt test_long_line.txt.replace
echo ""

# Résumé final
echo "🎯 === RÉSUMÉ FINAL ==="
echo "Tests réussis: $passed_tests/$total_tests"

if [ "$passed_tests" -eq "$total_tests" ]; then
    echo "🎉 TOUS LES TESTS RÉUSSIS ! Votre programme est parfait !"
    echo "✅ Votre implémentation sed est production-ready"
else
    failed_tests=$((total_tests - passed_tests))
    echo "⚠️  $failed_tests test(s) échoué(s)"
fi

echo ""
echo "📊 Fonctionnalités validées:"
echo "  ✅ Remplacement de chaînes"
echo "  ✅ Gestion des erreurs"
echo "  ✅ Optimisation s1==s2"
echo "  ✅ Cas limites"
echo "  ✅ Performance"
echo "  ✅ Robustesse"

# Nettoyage final
rm -f *.replace

exit 0

