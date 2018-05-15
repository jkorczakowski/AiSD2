
public class BTreeTester {

    public static void main(String[] args) {
        BTree<Integer, String> btree = new BTree<Integer, String>(5);
        System.out.println("***********Construct the tree**************");
        btree.insert(1, "s");
        btree.insert(2, "h");
        btree.insert(3, "i");
        btree.insert(9, "r");
        btree.insert(7, "l");
        btree.insert(4, "e");
        btree.insert(12, "y");
        btree.insert(24, "i");
        btree.insert(23, "s");
        btree.insert(112, "a");
        btree.insert(25, "w");
        btree.insert(33, "e");
        btree.insert(35, "s");
        btree.insert(38, "o");
        btree.insert(29, "m");
        btree.insert(5, "e");
        btree.insert(13, "d");
        //btree.insert(5, "d");
        System.out.println(btree.toString());
        System.out.format("Size of the tree: %d\n",btree.size());
        System.out.format("Height of the tree: %d\n", btree.height());
        System.out.println("****************Test deletion*****************");
		/*System.out.println("Delete 5: ");
		btree.delete(5);
		/*System.out.println(btree.toString());
		System.out.format("Size of the tree: %d\n",btree.size());
		System.out.format("Height of the tree: %d", btree.height());*/
		/*System.out.println("Delete 9: ");
		btree.delete(9);
		/*System.out.println(btree.toString());
		System.out.format("Size of the tree: %d\n",btree.size());
		System.out.format("Height of the tree: %d", btree.height());*/
		/*System.out.println("Delete 7: ");
		btree.delete(7);
		/*System.out.println(btree.toString());
		System.out.format("Size of the tree: %d\n",btree.size());
		System.out.format("Height of the tree: %d", btree.height());*/
		/*System.out.println("Delete 12: ");
		btree.delete(12);
		/*System.out.println(btree.toString());
		System.out.format("Size of the tree: %d\n",btree.size());
		System.out.format("Height of the tree: %d", btree.height());*/
		/*System.out.println("Delete 13: ");
		btree.delete(13);
		/*System.out.println(btree.toString());
		System.out.format("Size of the tree: %d\n",btree.size());
		System.out.format("Height of the tree: %d", btree.height());*/
		/*System.out.println("****Delete 35: ");
		btree.delete(35);
		/*System.out.println(btree.toString());
		System.out.format("Size of the tree: %d\n",btree.size());
		System.out.format("Height of the tree: %d\n", btree.height());*/
		/*System.out.println("Delete 29: ");
		btree.delete(29);
		/*System.out.println(btree.toString());
		System.out.format("Size of the tree: %d\n",btree.size());
		System.out.format("Height of the tree: %d", btree.height());*/
		/*System.out.println("Delete 25: ");
		btree.delete(25);
		/*System.out.println(btree.toString());
		System.out.format("Size of the tree: %d\n",btree.size());
		System.out.format("Height of the tree: %d", btree.height());*/
		/*System.out.println("Delete 24: ");
		btree.delete(24);
		/*System.out.println(btree.toString());
		System.out.format("Size of the tree: %d\n",btree.size());
		System.out.format("Height of the tree: %d", btree.height());*/
		/*System.out.println("Delete 112: ");
		btree.delete(112);
		/*System.out.println(btree.toString());
		System.out.format("Size of the tree: %d\n",btree.size());
		System.out.format("Height of the tree: %d\n", btree.height());*/
		/*System.out.println("Delete 4: ");
		btree.delete(4);
		/*System.out.println(btree.toString());
		System.out.format("Size of the tree: %d\n",btree.size());
		System.out.format("Height of the tree: %d\n", btree.height());*/
		/*System.out.println("Delete 1: ");
		btree.delete(1);
		/*System.out.println(btree.toString());
		System.out.format("Size of the tree: %d\n",btree.size());
		System.out.format("Height of the tree: %d\n", btree.height());*/
		/*System.out.println("Delete 2: ");
		btree.delete(2);
		/*System.out.println(btree.toString());
		System.out.format("Size of the tree: %d\n",btree.size());
		System.out.format("Height of the tree: %d", btree.height());*/
		/*System.out.println("Delete 23: ");
		btree.delete(23);
		/*System.out.println(btree.toString());
		System.out.format("Size of the tree: %d\n",btree.size());
		System.out.format("Height of the tree: %d", btree.height());*/
		/*System.out.println("Delete 3: ");
		btree.delete(3);
		System.out.println(btree.toString());
		System.out.format("Size of the tree: %d\n",btree.size());
		System.out.format("Height of the tree: %d", btree.height());*/
        System.out.println("****************Test deletion 2*****************");
        System.out.println("Delete 24: ");
        btree.delete(24);
        System.out.println(btree.toString());
        System.out.format("Size of the tree: %d\n",btree.size());
        System.out.format("Height of the tree: %d\n", btree.height());
        System.out.println("***Delete 23: ");
        btree.delete(23);
		/*System.out.println(btree.toString());
		System.out.format("Size of the tree: %d\n",btree.size());
		System.out.format("Height of the tree: %d\n", btree.height());*/
        System.out.println("Delete 12: ");
        btree.delete(12);
		/*System.out.println(btree.toString());
		System.out.format("Size of the tree: %d\n",btree.size());
		System.out.format("Height of the tree: %d\n", btree.height());*/
        System.out.println("Delete 33: ");
        btree.delete(33);
		/*System.out.println(btree.toString());
		System.out.format("Size of the tree: %d\n",btree.size());
		System.out.format("Height of the tree: %d\n", btree.height());*/
        System.out.println("Delete 9: ");
        btree.delete(9);
		/*System.out.println(btree.toString());
		System.out.format("Size of the tree: %d\n",btree.size());
		System.out.format("Height of the tree: %d\n", btree.height());*/
        System.out.println("Delete 5: ");
        btree.delete(5);
		/*System.out.println(btree.toString());
		System.out.format("Size of the tree: %d\n",btree.size());
		System.out.format("Height of the tree: %d\n", btree.height());*/
        System.out.println("Delete 13: ");
        btree.delete(13);
		/*System.out.println(btree.toString());
		System.out.format("Size of the tree: %d\n",btree.size());
		System.out.format("Height of the tree: %d\n", btree.height());*/
        System.out.println("Delete 112: ");
        btree.delete(112);
		/*System.out.println(btree.toString());
		System.out.format("Size of the tree: %d\n",btree.size());
		System.out.format("Height of the tree: %d\n", btree.height());*/
        System.out.println("Delete 29: ");
        btree.delete(29);
		/*System.out.println(btree.toString());
		System.out.format("Size of the tree: %d\n",btree.size());
		System.out.format("Height of the tree: %d\n", btree.height());*/
        System.out.println("Delete 35: ");
        btree.delete(35);
        System.out.println(btree.toString());
        System.out.format("Size of the tree: %d\n",btree.size());
        System.out.format("Height of the tree: %d\n", btree.height());


    }

}
