#include "screens.h"
#include "images.h"
#include "fonts.h"
#include "actions.h"
#include "styles.h"
#include "ui.h"

objects_t objects;

static void event_handler_cb_main_arc(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    if (event == LV_EVENT_VALUE_CHANGED) {
        lv_obj_t *ta = lv_event_get_target(e);
        int32_t value = lv_arc_get_value(ta);
        assignIntegerProperty(0, 10, 2, value, "Failed to assign Value in Arc widget");
    }
}

static void event_handler_cb_main_arc_2(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    if (event == LV_EVENT_VALUE_CHANGED) {
        lv_obj_t *ta = lv_event_get_target(e);
        int32_t value = lv_arc_get_value(ta);
        assignIntegerProperty(0, 11, 2, value, "Failed to assign Value in Arc widget");
    }
}

void create_screen_main() {
    lv_obj_t *obj = lv_obj_create(0);
    objects.main = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 800, 600);
    lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
    {
        lv_obj_t *parent_obj = obj;
        {
            // panel
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.panel = obj;
            lv_obj_set_pos(obj, 0, 0);
            lv_obj_set_size(obj, 800, 600);
            lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // log_lvgl
                    lv_obj_t *obj = lv_img_create(parent_obj);
                    objects.log_lvgl = obj;
                    lv_obj_set_pos(obj, 466, 214);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_img_set_src(obj, &img_logo_lvgl);
                    lv_obj_add_flag(obj, LV_OBJ_FLAG_ADV_HITTEST);
                    lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
                }
                {
                    // log_eez
                    lv_obj_t *obj = lv_img_create(parent_obj);
                    objects.log_eez = obj;
                    lv_obj_set_pos(obj, 71, 214);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_img_set_src(obj, &img_log_eez);
                    lv_obj_add_flag(obj, LV_OBJ_FLAG_ADV_HITTEST);
                    lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
                }
                {
                    // arc
                    lv_obj_t *obj = lv_arc_create(parent_obj);
                    objects.arc = obj;
                    lv_obj_set_pos(obj, 11, 76);
                    lv_obj_set_size(obj, 340, 404);
                    lv_arc_set_range(obj, 0, 3600);
                    lv_arc_set_bg_start_angle(obj, 91);
                    lv_arc_set_bg_end_angle(obj, 89);
                    lv_obj_add_event_cb(obj, event_handler_cb_main_arc, LV_EVENT_ALL, 0);
                }
                {
                    // arc_2
                    lv_obj_t *obj = lv_arc_create(parent_obj);
                    objects.arc_2 = obj;
                    lv_obj_set_pos(obj, 406, 76);
                    lv_obj_set_size(obj, 340, 404);
                    lv_arc_set_range(obj, 0, 60);
                    lv_arc_set_bg_start_angle(obj, 2);
                    lv_arc_set_bg_end_angle(obj, 1);
                    lv_obj_add_event_cb(obj, event_handler_cb_main_arc_2, LV_EVENT_ALL, 0);
                }
            }
        }
    }
}

void tick_screen_main() {
    {
        int32_t new_val = evalIntegerProperty(0, 10, 2, "Failed to evaluate Value in Arc widget");
        int32_t cur_val = lv_arc_get_value(objects.arc);
        if (new_val != cur_val) lv_arc_set_value(objects.arc, new_val);
    }
    {
        int32_t new_val = evalIntegerProperty(0, 11, 2, "Failed to evaluate Value in Arc widget");
        int32_t cur_val = lv_arc_get_value(objects.arc_2);
        if (new_val != cur_val) lv_arc_set_value(objects.arc_2, new_val);
    }
}


void create_screens() {
    lv_disp_t *dispp = lv_disp_get_default();
    lv_theme_t *theme = lv_theme_default_init(dispp, lv_palette_main(LV_PALETTE_BLUE), lv_palette_main(LV_PALETTE_RED), false, LV_FONT_DEFAULT);
    lv_disp_set_theme(dispp, theme);
    
    create_screen_main();
}

typedef void (*tick_screen_func_t)();

tick_screen_func_t tick_screen_funcs[] = {
    tick_screen_main,
};

void tick_screen(int screen_index) {
    tick_screen_funcs[screen_index]();
}
