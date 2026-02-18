import org.junit.Test;

import static org.junit.Assert.assertFalse;
import static org.junit.Assert.assertTrue;

public class TestTree {

    @Test
    public void test1() {
        Tree t = new Tree(new Node(new Node(null, null, new Object[]{new Coconut(), new Apple()}), new Node(null, null, new Object[]{new Pear(), new Coconut()}), new Object[]{new Banana(), new Orange()}));
        assertFalse(t.isOneTypeOfFruitOnNode());
        assertFalse(t.isSameOneTypeOfFruitOnChildren());
    }

    @Test
    public void test2() {
        Tree t = new Tree(new Node(new Node(null, null, new Object[]{new Apricot(), new Strawberry()}), new Node(null, null, new Object[]{new Orange(), new Apple()}), new Object[]{new Apricot(), new Pear()}));
        assertFalse(t.isOneTypeOfFruitOnNode());
        assertFalse(t.isSameOneTypeOfFruitOnChildren());
    }

    @Test
    public void test3() {
        Tree t = new Tree(new Node(new Node(null, null, new Object[]{new Strawberry(), new Strawberry()}), new Node(null, null, new Object[]{new Apricot(), new Apricot()}), new Object[]{new Apricot(), new Apricot()}));
        assertTrue(t.isOneTypeOfFruitOnNode());
        assertFalse(t.isSameOneTypeOfFruitOnChildren());
    }

    @Test
    public void test4() {
        Tree t = new Tree(new Node(new Node(null, null, new Object[]{new Pear(), new Pear()}), new Node(null, null, new Object[]{new Plum(), new Plum()}), new Object[]{new Mango(), new Mango()}));
        assertTrue(t.isOneTypeOfFruitOnNode());
        assertFalse(t.isSameOneTypeOfFruitOnChildren());
    }

    @Test
    public void test5() {
        Tree t = new Tree(new Node(new Node(null, null, new Object[]{new Grape(), new Apricot()}), new Node(null, null, new Object[]{new Peach(), new Pear()}), new Object[]{new Plum(), new Orange()}));
        assertFalse(t.isOneTypeOfFruitOnNode());
        assertFalse(t.isSameOneTypeOfFruitOnChildren());
    }

    @Test
    public void test6() {
        Tree t = new Tree(new Node(new Node(null, null, new Object[]{new Plum(), new Plum()}), new Node(null, null, new Object[]{new Grape(), new Peach()}), new Object[]{new Peach(), new Pear()}));
        assertFalse(t.isOneTypeOfFruitOnNode());
        assertFalse(t.isSameOneTypeOfFruitOnChildren());
    }

    @Test
    public void test7() {
        Tree t = new Tree(new Node(new Node(null, null, new Object[]{new Strawberry(), new Strawberry()}), new Node(null, null, new Object[]{new Strawberry(), new Strawberry()}), new Object[]{new Pear(), new Pear()}));
        assertTrue(t.isOneTypeOfFruitOnNode());
        assertTrue(t.isSameOneTypeOfFruitOnChildren());
    }

    @Test
    public void test8() {
        Tree t = new Tree(new Node(new Node(new Node(null, null, new Object[]{new Strawberry(), new Strawberry(), new Strawberry(), new Strawberry()}), new Node(null, null, new Object[]{new Strawberry(), new Strawberry(), new Strawberry(), new Strawberry()}), new Object[]{new Peach(), new Peach(), new Peach(), new Peach()}), new Node(null, null, new Object[]{new Peach(), new Peach(), new Peach(), new Peach()}), new Object[]{new Pear(), new Pear(), new Pear(), new Pear()}));
        assertTrue(t.isOneTypeOfFruitOnNode());
        assertTrue(t.isSameOneTypeOfFruitOnChildren());
    }

    @Test
    public void test9() {
        Tree t = new Tree(new Node(new Node(new Node(null, null, new Object[]{new Plum(), new Grape(), new Mango(), new Plum()}), new Node(null, null, new Object[]{new Strawberry(), new Grape(), new Plum(), new Apple()}), new Object[]{new Pear(), new Mango(), new Pear(), new Grape()}), new Node(new Node(null, null, new Object[]{new Apricot(), new Banana(), new Strawberry(), new Peach()}), new Node(null, null, new Object[]{new Orange(), new Apricot(), new Coconut(), new Pear()}), new Object[]{new Apple(), new Grape(), new Peach(), new Banana()}), new Object[]{new Orange(), new Apple(), new Coconut(), new Coconut()}));
        assertFalse(t.isOneTypeOfFruitOnNode());
        assertFalse(t.isSameOneTypeOfFruitOnChildren());
    }

    @Test
    public void test10() {
        Tree t = new Tree(new Node(new Node(new Node(null, null, new Object[]{new Apricot(), new Grape(), new Apple(), new Banana()}), new Node(null, null, new Object[]{new Plum(), new Orange(), new Apple(), new Mango()}), new Object[]{new Apricot(), new Pear(), new Coconut(), new Strawberry()}), new Node(new Node(null, null, new Object[]{new Grape(), new Mango(), new Orange(), new Apricot()}), new Node(null, null, new Object[]{new Mango(), new Orange(), new Pear(), new Peach()}), new Object[]{new Coconut(), new Pear(), new Pear(), new Strawberry()}), new Object[]{new Orange(), new Orange(), new Apple(), new Banana()}));
        assertFalse(t.isOneTypeOfFruitOnNode());
        assertFalse(t.isSameOneTypeOfFruitOnChildren());
    }

    @Test
    public void test11() {
        Tree t = new Tree(new Node(new Node(new Node(null, null, new Object[]{new Mango(), new Mango(), new Mango(), new Mango()}), new Node(null, null, new Object[]{new Grape(), new Grape(), new Grape(), new Grape()}), new Object[]{new Orange(), new Orange(), new Orange(), new Orange()}), new Node(new Node(null, null, new Object[]{new Apple(), new Apple(), new Apple(), new Apple()}), new Node(null, null, new Object[]{new Banana(), new Banana(), new Banana(), new Banana()}), new Object[]{new Plum(), new Plum(), new Plum(), new Plum()}), new Object[]{new Grape(), new Grape(), new Grape(), new Grape()}));
        assertTrue(t.isOneTypeOfFruitOnNode());
        assertFalse(t.isSameOneTypeOfFruitOnChildren());
    }

    @Test
    public void test12() {
        Tree t = new Tree(new Node(new Node(new Node(null, null, new Object[]{new Banana(), new Banana(), new Banana(), new Banana()}), new Node(null, null, new Object[]{new Coconut(), new Coconut(), new Coconut(), new Coconut()}), new Object[]{new Apple(), new Apple(), new Apple(), new Apple()}), new Node(new Node(null, null, new Object[]{new Strawberry(), new Strawberry(), new Strawberry(), new Strawberry()}), new Node(null, null, new Object[]{new Strawberry(), new Strawberry(), new Strawberry(), new Strawberry()}), new Object[]{new Strawberry(), new Strawberry(), new Strawberry(), new Strawberry()}), new Object[]{new Apricot(), new Apricot(), new Apricot(), new Apricot()}));
        assertTrue(t.isOneTypeOfFruitOnNode());
        assertFalse(t.isSameOneTypeOfFruitOnChildren());
    }
}

class Peach {}
class Pear {}
class Apricot {}
class Strawberry {}
class Apple {}
class Banana {}
class Grape {}
class Orange {}
class Plum {}
class Mango {}
class Coconut {}