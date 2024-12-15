        #include "DisjSets.h"

        /**
         * Construct the disjoint sets object.
         * numElements is the initial number of disjoint sets.
         */
        DisjSets::DisjSets( int numElements ) 
        {
            for( int i = 0; i < numElements; i++ )
                s.push_back(-1);
        }
		//get the content of an element
		int DisjSets::getIt (int j)
		{
			return s[j];
		}

        /**
         * Union two disjoint sets.
         * Now include error checking,
         * root1 will be set to the root of set 1 if it's not already a root
         * root2 will be set to the root of set 1 if it's not already a root
		 * function does nothing if root1==root2
         */
        void DisjSets::unionSets( int root1, int root2 )
        {
			// check root status
			if (root1>=0) // not yet a root
			  root1 = find1(root1); // set to root, use find1 to preserve the tree
			if (root2>=0) // not yet a root
			  root2 = find1(root2);
			if (root1==root2) // save root
				return;
			
			// the rest is original code from book author
            if( s[ root2 ] < s[ root1 ] )  

            // s[root2] = -3: Tree rooted at root2 has height 3.
            // s[root1] = -1: Tree rooted at root1 has height 1.
				// root2 is deeper, i.e., |s[root2]| > |s[root1]|
                
                s[ root1 ] = root2;        // Make root2 new root
            else
            {
                if( s[ root1 ] == s[ root2 ] )
                    s[ root1 ]--;          // Update height of root1 if same
                s[ root2 ] = root1;        // Make root1 new root
            }
        }


        /**
         * Perform a find.
         * Error checks omitted again for simplicity.
         * Return the set containing x.
         */
        int DisjSets::find1( int x ) const
        {
            if( s[ x ] < 0 ) // already the root
                return x;
            else
                return find1( s[ x ] );
        }


        /**
         * Perform a find with path compression.
         * Error checks omitted again for simplicity.
         * Return the set containing x.
         */
        int DisjSets::find( int x )
        {
            if( s[ x ] < 0 )
                return x;
            else
                return s[ x ] = find( s[ x ] ); // compress path with each find
        }

