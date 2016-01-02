/*
 * File:    test.cpp
 * Author:  Pete Goodliffe
 * Version: 1.10
 * Created: 7 June 2001
 *
 * Purpose: C++ debugging support library
 *
 * Copyright (c) Pete Goodliffe 2001-2002 (pete@cthree.org)
 *
 * This file is modifiable/redistributable under the terms of the GNU
 * Lesser General Public License.
 *
 * You should have recieved a copy of the GNU General Public License along
 * with this program; see the file COPYING. If not, write to the Free Software
 * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 0211-1307, USA.
 */

#include "dbg.h"

#include <iostream>
#include <fstream>

#ifdef TEST_WITHOUT_ANY_LIBRARY_USAGE
#undef DO_DBG
#else
#define DO_DBG
#endif

// This is in dbg.cpp too. Sigh.
#ifdef _MSC_VER
#define STDCLK
#else
#define STDCLK std
#endif

/******************************************************************************
 * Test harness
 *****************************************************************************/

bool ret_true() { return true; }
bool ret_false() { return false; }

class post_test
{
    public:
        post_test() : a(10) {}
        void do_test()
        {
            #ifdef DO_DBG
                dbg::assertion(DBG_ASSERTION(invariant()));
                dbg::post_mem_fun<post_test>
                    pmf(this, &post_test::invariant, DBG_HERE);
                dbg::post b(&ret_false, DBG_HERE);
                dbg::out(dbg::info) << dbg::prefix() << "hello\n";
            #endif
            a = 9;
        }
    private:
        bool invariant()
        {
            return a == 10;
        }
        int a;
};

int main()
{
    std::cout << "********************************************************\n";
    std::cout << "dbg test rig\n";

    std::cout << "Built with DBG_ENABLED ";
#ifdef DBG_ENABLED
    std::cout << "on \n";
#else
    std::cout << "off\n";
#endif
    std::cout << "Built with API calling enabled: ";
    #ifdef DO_DBG
        std::cout << "yes";
    #else
        std::cout << "no ";
    #endif
    std::cout << "\n";
    std::cout << "********************************************************\n";
    //dbg::out(dbg::tracing) << DBG_HERE << "\n"; // doesn't work on MSCV 6.0
    #ifdef DO_DBG
        dbg::out(dbg::tracing) << DBG_HERE << "\n";
    #endif

    std::cout << "Switching assertions to non fatal\n";
    #ifdef DO_DBG
        dbg::enable(dbg::all, true);
        dbg::attach_ostream(dbg::all, std::cerr);
        dbg::attach_ostream(dbg::all, dbg::default_source, std::cerr);
        dbg::set_assertion_behaviour(dbg::all, dbg::assertions_continue);
        dbg::set_assertion_period(CLOCKS_PER_SEC*1);
        dbg::enable_level_prefix(true);
        dbg::enable_time_prefix(true);
    #endif
    std::cout << "--------------------------------------------------------\n";
    #ifdef DO_DBG
        dbg::out(dbg::tracing) << DBG_HERE << "\n";
    #endif

    std::cout << "Testing dbg::assertion\n";
    #ifdef DO_DBG
        dbg::assertion(dbg::info, DBG_ASSERTION(1 == 0));
    #endif
    std::cout << "--------------------------------------------------------\n";
    #ifdef DO_DBG
        dbg::out(dbg::tracing) << DBG_HERE << "\n";
    #endif

    std::cout << "Testing dbg::sentinel\n";
    {
        #ifdef DO_DBG
            dbg::sentinel(dbg::info, DBG_HERE);
        #endif
    }
    std::cout << "--------------------------------------------------------\n";
    #ifdef DO_DBG
        dbg::out(dbg::tracing) << DBG_HERE << "\n";
    #endif

    std::cout << "Testing dbg::unimplemented\n";
    {
        #ifdef DO_DBG
            dbg::unimplemented(dbg::info, DBG_HERE);
        #endif
    }

    std::cout << "--------------------------------------------------------\n";
    #ifdef DO_DBG
        dbg::out(dbg::tracing) << DBG_HERE << "\n";
    #endif

    std::cout << "Testing dbg::trace\n";
    {
        #ifdef DO_DBG
            dbg::trace trace1("test function 1");
            dbg::trace trace2("test function 2");
            dbg::trace trace3(DBG_HERE);
            dbg::out(dbg::tracing) << dbg::indent(dbg::tracing) << "hello\n";
        #endif
    }
    std::cout << "--------------------------------------------------------\n";
    #ifdef DO_DBG
        dbg::out(dbg::tracing) << DBG_HERE << "\n";
    #endif

    std::cout << "Testing dbg::pre_post\n";
    {

        post_test test_obj;
        test_obj.do_test();
    }

    std::cout << "--------------------------------------------------------\n";
    #ifdef DO_DBG
        dbg::out(dbg::tracing) << DBG_HERE << "\n";
    #endif

    std::cout << "Testing dbg::out\n";
    {
        #ifdef DO_DBG
            dbg::out(dbg::info) << "Debug output is of more than " << 1
                                << " standard type!\n";
        #endif
    }

    std::cout << "--------------------------------------------------------\n";
    #ifdef DO_DBG
        dbg::out(dbg::tracing) << DBG_HERE << "\n";
    #endif

    std::cout << "Testing dbg::check_ptr\n";
    {
        int a_val = 1, b_val = 0;
        int *a = &a_val, *b = &b_val;
        #ifdef DO_DBG
            dbg::check_ptr(dbg::info, a, DBG_HERE);
            dbg::check_ptr(dbg::info, b, DBG_HERE);
        #endif
        std::cout << "Using some vars: " << *a << "," << *b << "\n";
    }

    std::cout << "--------------------------------------------------------\n";
    #ifdef DO_DBG
        dbg::out(dbg::tracing) << DBG_HERE << "\n";
    #endif

    std::cout << "Testing dbg::check_bounds\n";
    {
        int a[10];
        int index = 9;
        #ifdef DO_DBG
            dbg::check_bounds(dbg::info, index, a, DBG_HERE);
            dbg::check_bounds(dbg::info, 10, a, DBG_HERE);
        #endif
        a[index] = 4;
    }

    std::cout << "\n********************************************************\n";
    #ifdef DO_DBG
        dbg::out(dbg::tracing) << DBG_HERE << "\n";
    #endif

    std::cout << "Testing debug sources\n";
    {
        const char *SRC1 = "source type 1";
        const char *SRC2 = "source type 2";
        std::cout << "Using some vars: " << SRC1 << "," << SRC2 << "\n";
        std::ofstream fout1("SRC1.out");
        std::ofstream fout2("SRC2.out");

        #ifdef DO_DBG
            // Turn off all streams. Enable info by default. Attach
            // std::cerr to all sources by default. The new streams, as
            // they are added, should pick up these defaults. Note
            // that just mentioning a source brings it into existance
            // (if it doesn't already exist) as a copy of the default
            // source.
            dbg::enable_all(dbg::all, false);
            dbg::enable(dbg::info, dbg::default_source, true);
            dbg::attach_ostream(dbg::all, dbg::default_source, std::cerr);

            // Disable output on info for SRC1. Should remain on for SRC2
            dbg::enable(dbg::info, SRC1, false);

            // Try attaching additional streams to the two sources.
            dbg::attach_ostream(dbg::all, SRC1, fout1);
            dbg::attach_ostream(dbg::all, SRC2, fout2);

            // Modify the default source. Should have NO effect,
            // since our two sources already exist.
            dbg::enable(dbg::all, dbg::default_source, false);

            // Do some output on the two sources now.

            // Should not print
            dbg::assertion(dbg::info, SRC1, DBG_ASSERTION(1 == 0));

            // Modify the state of the sources
            dbg::enable(dbg::info, SRC1, true);
            dbg::enable(dbg::tracing, SRC1, true);

            // Should print
            dbg::assertion(dbg::info, SRC1, DBG_ASSERTION(1 == 0));
            dbg::assertion(dbg::info, SRC2, DBG_ASSERTION(1 == 0));

            // Should not print
            dbg::assertion(dbg::warning, SRC2, DBG_ASSERTION(1 == 0));

            // Should print for SRC1, not for SRC2
            dbg::trace tr1(SRC1, DBG_HERE);
            dbg::trace tr2(SRC1, "block 2");
            dbg::trace tr3(SRC2, "block 3");
            {
                dbg::trace tr4(SRC1, "block 4");

                // Disable tracing on SRC1 in mid-stream, to see what happens.
                dbg::enable(dbg::tracing, SRC1, false);
            }

            // Re-enable tracing on SRC1, for kicks
            dbg::enable(dbg::tracing, SRC1, true);

            // Try a post object out. It won't print unless
            // we turn the warning level on.
            dbg::enable(dbg::warning, SRC1, true);
            dbg::post b(SRC1, &ret_false, DBG_HERE);
        #endif
    }

    dbg::enable(dbg::all, true);

    std::cout << "\n********************************************************\n";
    #ifdef DO_DBG
        dbg::out(dbg::tracing) << DBG_HERE << "\n";
    #endif

    std::cout << "Testing dbg::set_assertion_period and looping\n";
    {
        for (STDCLK::clock_t now = STDCLK::clock();
             STDCLK::clock() < now + (CLOCKS_PER_SEC*5);
             /*nothing*/)
        {
            #ifdef DO_DBG
                dbg::assertion(DBG_ASSERTION(1 == 0));
            #endif
        }
    }

    std::cout << "\n********************************************************\n";
    #ifdef DO_DBG
        dbg::out(dbg::tracing) << DBG_HERE << "\n";
    #endif
    std::cout << "Test rig completed succesffully.\n";
    std::cout << " ... finishing off fatal for kicks ...\n";
    #ifdef DO_DBG
        dbg::assertion(dbg::fatal, DBG_ASSERTION(1 == 0));
    #endif

    return 0;
}

