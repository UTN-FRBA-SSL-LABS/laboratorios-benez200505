#include <stdio.h>
#include "../src/carrito.h"
#include "minunit/minunit.h"

/*
 * Tests de integracion: verifican que las funciones trabajan bien
 * en combinacion, no de forma aislada.
 */

/* ═══════════════════════════════════════════════════════════════════════════
 *  PARTE D — Escribir el test guiado (ver README.md, Parte 8)
 * ═══════════════════════════════════════════════════════════════════════════ */

void test_compra_con_descuento(void) {
    printf("\n[compra con descuento]\n");
    Carrito c;
    carrito_init(&c);
    
    Producto p1 = {"Pan", 200, 3};   /* Subtotal: 600 */
    Producto p2 = {"Leche", 350, 2}; /* Subtotal: 700 */
    
    carrito_agregar(&c, p1);
    carrito_agregar(&c, p2);
    
    int total = carrito_total(&c);
    ASSERT_IGUAL(1300, total);
    
    int con_descuento = carrito_descuento(total, 10);
    ASSERT_IGUAL(1170, con_descuento);
}
/* ═══════════════════════════════════════════════════════════════════════════
 *  PARTE E — Disenar un test propio (ver README.md, Parte 9)
 * ═══════════════════════════════════════════════════════════════════════════ */


void test_agregar_hasta_llenar(void) {
    printf("\n[agregar hasta llenar]\n");
    Carrito c;
    carrito_init(&c);
    Producto p = {"Item", 100, 1};
    
    /* 1. Llenar el carrito hasta su capacidad máxima (4 productos) */
    carrito_agregar(&c, p);
    carrito_agregar(&c, p);
    carrito_agregar(&c, p);
    carrito_agregar(&c, p);
    
    /* 2. Verificar que el conteo es MAX_ITEMS (4) */
    ASSERT_IGUAL(4, carrito_contar(&c));
    
    /* 3. Verificar que intentar agregar uno más devuelve 0 */
    ASSERT_IGUAL(0, carrito_agregar(&c, p));
    
    /* 4. Verificar que el conteo sigue siendo MAX_ITEMS (4) */
    ASSERT_IGUAL(4, carrito_contar(&c));
}
int main(void) {
    printf("=== Tests de integracion ===\n");
    
    test_compra_con_descuento();  
    test_agregar_hasta_llenar();  
    
    RESUMEN();
    return EXIT_CODE();
}
