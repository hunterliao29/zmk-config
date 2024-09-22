#define XXX &none
#define MAG &mo U_MAGIC

#define MAP_LAYER( \
    k00, k01, k02, k03, k04, k05, k06, k07, k08, k09, \
    k10, k11, k12, k13, k14, k15, k16, k17, k18, k19, \
    k20, k21, k22, k23, k24, k25, k26, k27, k28, k29, \
              k30, k31, k32, k33, k34, k35            \
) \
XXX  XXX  XXX  XXX  XXX                                               XXX  XXX  XXX  XXX  XXX \
XXX  XXX  XXX  XXX  XXX  XXX                                     XXX  XXX  XXX  XXX  XXX  XXX \
XXX  k00  k01  k02  k03  k04                                     k05  k06  k07  k08  k09  XXX \
XXX  k10  k11  k12  k13  k14                                     k15  k16  k17  k18  k19  XXX \
XXX  k20  k21  k22  k23  k24  XXX  XXX  XXX       XXX  XXX  XXX  k25  k26  k27  k28  k29  XXX \
MAG  XXX  XXX  XXX  XXX       k30  k31  k32       k33  k34  k35       XXX  XXX  XXX  XXX  MAG


#define MAP_LAYER_MAGIC( \
    k00, k01, k02, k03, k04, k05, k06, k07, k08, k09, \
    k10, k11, k12, k13, k14, k15, k16, k17, k18, k19, \
    k20, k21, k22, k23, k24, k25, k26, k27, k28, k29, \
              k30, k31, k32, k33, k34, k35            \
) \
&bt BT_CLR  XXX             XXX             XXX             XXX                                                                                       XXX XXX XXX XXX &bt BT_CLR \
XXX         XXX             XXX             XXX             XXX             XXX                                                                   XXX XXX XXX XXX XXX XXX \
XXX         &rgb_ug RGB_SPI &rgb_ug RGB_SAI &rgb_ug RGB_HUI &rgb_ug RGB_BRI &rgb_ug RGB_TOG                                                       XXX XXX XXX XXX XXX XXX \
&bootloader &rgb_ug RGB_SPD &rgb_ug RGB_SAD &rgb_ug RGB_HUD &rgb_ug RGB_BRD &rgb_ug RGB_EFF                                                       XXX XXX XXX XXX XXX &bootloader \
&sys_reset  XXX             XXX             XXX             XXX             XXX             &bt BT_SEL 2  &bt BT_SEL 3  XXX          XXX XXX XXX  XXX XXX XXX XXX XXX &sys_reset \
XXX         XXX             XXX             XXX             XXX                             &bt BT_SEL 0  &bt BT_SEL 1  &out OUT_USB XXX XXX XXX      XXX XXX XXX XXX XXX

#ifdef MOERGO
#include <dt-bindings/zmk/rgb.h>
#undef MAG
#define MAG &magic U_MAGIC 0
/ {
    behaviors {
        magic: magic_hold_tap {
            compatible = "zmk,behavior-hold-tap";
            label = "MAGIC_HOLD_TAP";
            #binding-cells = <2>;
            flavor = "tap-preferred";
            tapping-term-ms = <200>;
            bindings = <&mo>, <&rgb_ug_status_macro>;
        };
    };

    macros {
        rgb_ug_status_macro: rgb_ug_status_macro_0 {
            label = "RGB_UG_STATUS";
            compatible = "zmk,behavior-macro";
            #binding-cells = <0>;
            bindings = <&rgb_ug RGB_STATUS>;
        };
    };
};
#endif
