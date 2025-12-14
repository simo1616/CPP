#include <iostream>
#include <string>

// Tes fonctions (déjà définies ailleurs) :
bool CheckBisex(int annee);
bool strCheckYear(std::string const& annee, int& out, int const d, int const m);
bool strCheckMounth(std::string const& m, int& out);
bool strCheckDay(std::string const& day, int& out);

static void printLine(const std::string& title)
{
    std::cout << "\n===== " << title << " =====" << std::endl;
}

static void testBisex()
{
    printLine("TEST CheckBisex (annees)");
    int years[] = {2008, 2009, 2012, 2016, 2019, 2020, 2023, 2024, 2100, 2000, 1900};
    int size = sizeof(years) / sizeof(years[0]);

    for (int i = 0; i < size; i++)
    {
        bool b = CheckBisex(years[i]);
        std::cout << "annee " << years[i] << " -> "
                  << (b ? "bissextile (fev 29)" : "non (fev 28)") << std::endl;
    }
}

static void testStrCheckDay()
{
    printLine("TEST strCheckDay");
    std::string days[] = {"1","9","30","31","0","32","-1","01"," 1","1 ","1a","a1",""};
    int size = sizeof(days) / sizeof(days[0]);

    for (int i = 0; i < size; i++)
    {
        int d;
        bool ok = strCheckDay(days[i], d);
        std::cout << "day='" << days[i] << "' -> "
                  << (ok ? "OK " : "FAUX")
                  << (ok ? ("(" + std::string("val=") + (d < 10 ? "0" : "") ) : "")
                  << (ok ? "" : "") << std::endl;
        if (ok)
            std::cout << "   parsed day = " << d << std::endl;
    }
}

static void testStrCheckMounth()
{
    printLine("TEST strCheckMounth");
    std::string months[] = {"1","2","12","0","13","-1","02"," 2","2 ","2a","a2",""};
    int size = sizeof(months) / sizeof(months[0]);

    for (int i = 0; i < size; i++)
    {
        int m;
        bool ok = strCheckMounth(months[i], m);
        std::cout << "month='" << months[i] << "' -> "
                  << (ok ? "OK" : "FAUX");
        if (ok) std::cout << " (parsed=" << m << ")";
        std::cout << std::endl;
    }
}

static void testStrCheckYear()
{
    printLine("TEST strCheckYear (seul via d/m donnes)");
    // On fixe un jour/mois "safe" pour tester l’année sans que février gêne
    int d = 15;
    int m = 1;

    std::string years[] = {
        "2008", "2009", "2010", "2024", "2100", "2101",
        "abcd", "2024a", "-2024", "+2024", " 2024", "2024 ",
        "", "999999999999999999999999999999" // overflow long -> errno/ERANGE
    };

    int size = sizeof(years) / sizeof(years[0]);

    for (int i = 0; i < size; i++)
    {
        int y;
        bool ok = strCheckYear(years[i], y, d, m);
        std::cout << "year='" << years[i] << "' -> "
                  << (ok ? "OK" : "FAUX");
        if (ok) std::cout << " (parsed=" << y << ")";
        std::cout << std::endl;
    }
}

static void testDatesComplete()
{
    printLine("TEST DATE COMPLETE (YYYY-MM-DD) - cas limites + tous les mois");

    struct TestDate { std::string y; std::string m; std::string d; const char* expect; };

    TestDate tests[] = {
        // bornes métier
        {"2008","12","31","FAUX"},
        {"2009","01","01","OK"},
        {"2100","12","31","OK"},
        {"2101","01","01","FAUX"},

        // février (bissextile / non)
        {"2023","02","28","OK"},
        {"2023","02","29","FAUX"},
        {"2024","02","29","OK"},
        {"2024","02","30","FAUX"},
        {"2100","02","28","OK"},
        {"2100","02","29","FAUX"},
        {"2000","02","29","FAUX"}, // hors plage même si bissextile

        // mois à 30 jours
        {"2023","04","30","OK"},
        {"2023","04","31","FAUX"},
        {"2023","06","30","OK"},
        {"2023","06","31","FAUX"},
        {"2023","09","30","OK"},
        {"2023","09","31","FAUX"},
        {"2023","11","30","OK"},
        {"2023","11","31","FAUX"},

        // mois à 31 jours
        {"2023","01","31","OK"},
        {"2023","03","31","OK"},
        {"2023","05","31","OK"},
        {"2023","07","31","OK"},
        {"2023","08","31","OK"},
        {"2023","10","31","OK"},
        {"2023","12","31","OK"},

        // invalid month/day format
        {"2023","00","10","FAUX"},
        {"2023","13","10","FAUX"},
        {"2023","01","00","FAUX"},
        {"2023","01","32","FAUX"},

        // strings invalides / espaces
        {"abcd","01","01","FAUX"},
        {"2023","ab","01","FAUX"},
        {"2023","01","ab","FAUX"},
        {" 2023","01","01","FAUX"},
        {"2023 ","01","01","FAUX"},
        {"2023"," 1","01","FAUX"},
        {"2023","01","1 ","FAUX"},
        {"2023","+01","01","FAUX"},
        {"2023","01","+01","FAUX"}
    };

    int size = sizeof(tests) / sizeof(tests[0]);

    for (int i = 0; i < size; i++)
    {
        int y, m, d;
        bool ok = true;

        if (!strCheckDay(tests[i].d, d)) ok = false;
        if (!strCheckMounth(tests[i].m, m)) ok = false;
        if (ok && !strCheckYear(tests[i].y, y, d, m)) ok = false;

        std::cout << tests[i].y << "-" << tests[i].m << "-" << tests[i].d
                  << " -> " << (ok ? "OK" : "FAUX")
                  << " | attendu: " << tests[i].expect;

        if (ok && m == 2)
            std::cout << " (fevrier: " << (CheckBisex(y) ? "29j" : "28j") << ")";

        std::cout << std::endl;
    }
}

int main()
{
    testBisex();
    testStrCheckDay();
    testStrCheckMounth();
    testStrCheckYear();
    testDatesComplete();
    return 0;
}
