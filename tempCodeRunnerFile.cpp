// Push i pomiar czasu dla SLL1
        plik.clear();
        plik.seekg(0, std::ios::beg);
        auto start3 = high_resolution_clock::now();
        while (plik >> wartosc_int) 
        {
            one_way_list1.Addrand(wartosc_int);
        }
        auto stop3 = high_resolution_clock::now();
        auto duration3 = duration_cast<microseconds>(stop3 - start3);
        array[2][i] = duration3.count();

        // Pop i pomiar czasu dla SLL1
        auto start4 = high_resolution_clock::now();
        while (one_way_list1.getSize() > 0) 
        {
            one_way_list1.Dltrand();
        }
        auto stop4 = high_resolution_clock::now();
        auto duration4 = duration_cast<microseconds>(stop4 - start4);
        array[3][i] = duration4.count();