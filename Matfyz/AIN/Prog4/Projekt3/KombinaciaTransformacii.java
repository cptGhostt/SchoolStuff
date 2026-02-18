record KombinaciaTransformacii(Transformacia transformaciaA, Transformacia transformaciaB) implements Transformacia {
    public String[] aplikuj(String[] s) {
        return transformaciaA.aplikuj(transformaciaB.aplikuj(s));
    }
}
