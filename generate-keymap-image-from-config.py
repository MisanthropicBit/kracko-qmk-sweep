#!/usr/bin/env python

# Based on the generator script by Matt Gemmell but generates the image from a
# configuration file instead of parsing a C or JSON keymap

import argparse
import html
import json
import re
from string import Template
import sys


_svg_defaults = {}

_required_config_fields = [
  "name",
  "id",
  "split",
  "rows",
  "columns",
  "thumb_keys",
  "layout",
]

# # We'll just strip the keycode_prefix if a keycode isn't found in key_names
keycode_prefix = "KC_"

key_names = {
    'KC_NO': {'label': '', 'title': ''},
    'M_UNDO': {'label': 'Undo', 'title': 'Undo'},
    'M_CUT': {'label': 'Cut', 'title': 'Cut'},
    'M_COPY': {'label': 'Copy', 'title': ''},
    'M_PSTE': {'label': 'Paste', 'title': ''},
    'M_SAVE': {'label': 'Save', 'title': ''},
    'W1': {'label': 'W1', 'title': ''},
    'W2': {'label': 'W2', 'title': ''},
    'W3': {'label': 'W3', 'title': ''},
    'W4': {'label': 'W4', 'title': ''},
    'W5': {'label': 'W5', 'title': ''},
    'W6': {'label': 'W6', 'title': ''},
    'TG_QWTY': {'label': 'To QWERTY', 'title': ''},
    'KC_HOME': {'label': 'Home', 'title': ''},
    'KC_END': {'label': 'End', 'title': ''},
    'KC_DEL': {'label': 'Del', 'title': ''},
    'TAB_L': {'label': 'Prev Tab', 'title': ''},
    'TAB_R': {'label': 'Next Tab', 'title': ''},
    'ALF': {'label': 'Alfred', 'title': 'Alfred'},
    'HOOK': {'label': 'Hook', 'title': 'Hook'},
    'LHLF': {'label': 'Resize left', 'title': ''},
    'RHLF': {'label': 'Resize right', 'title': ''},
    'FULL': {'label': 'Resize full', 'title': ''},
    'OS_SHFT': {'label': '&#8679;', 'title': 'Shift'},
    'OS_CTRL': {'label': '&#94;', 'title': 'Control'},
    'MOD_LCTL': {'label': '^', 'title': 'Option'},
    'OS_ALT': {'label': '&#8997;', 'title': 'Option'},
    'MOD_LALT': {'label': '&#8997;', 'title': 'Option'},
    'KC_LALT': {'label': '&#8997;', 'title': 'Option'},
    'OS_CMD': {'label': '&#8984;', 'title': 'Command'},
    'KC_LCMD': {'label': '&#8984;', 'title': 'Command'},
    'MOD_LGUI': {'label': '&#8984;', 'title': 'Command'},
    'SW_APP': {'label': 'Switch App', 'title': ''},
    'KC_LSFT': {'label': '&#8679;', 'title': 'Shift'},
    'MOD_LSFT': {'label': '&#8679;', 'title': 'Shift'},
    'NAV_SPC': {'label': '&#9251;', 'title': ''},
    'NUM': {'label': 'Num', 'title': ''},
    'SYM': {'label': 'Sym', 'title': ''},
    'WNAV': {'label': 'Work space', 'title': ''},
    'FUN': {'label': 'Fun', 'title': ''},
    'KC_VOLD': {'label': '&#128265;', 'title': 'Volume Down'},
    'KC_AUDIO_VOL_DOWN': {'label': '&#128265;', 'title': 'Volume Down'},
    'KC_MUTE': {'label': '&#128263;', 'title': 'Mute'},
    'KC_AUDIO_MUTE': {'label': '&#128263;', 'title': 'Mute'},
    'KC_VOLU': {'label': '&#128266;', 'title': 'Volume Up'},
    'KC_AUDIO_VOL_UP': {'label': '&#128266;', 'title': 'Volume Up'},
    'KC_BRIGHT_UP': {'label': '&#128262;', 'title': 'Volume Up'},
    'KC_BRIGHT_DOWN': {'label': '&#128261;', 'title': 'Volume Up'},
    'QK_BOOTLOADER': {'label': '&#9889;', 'title': 'Previous Track'},
    'KC_MPRV': {'label': '&#9198;', 'title': 'Previous Track'},
    'KC_MPLY': {'label': '&#9199;', 'title': 'Play/Pause'},
    'KC_MEDIA_PLAY_PAUSE': {'label': '&#9199;', 'title': 'Play/Pause'},
    'KC_MNXT': {'label': '&#9197;', 'title': 'Next Track'},
    'KC_QUOT': {'label': "'", 'title': ''},
    'DK_QUOT': {'label': "'", 'title': ''},
    'KC_COMM': {'label': ',', 'title': ''},
    'KC_COMMA': {'label': ',', 'title': ''},
    'KC_DOT': {'label': '.', 'title': ''},
    'KC_SLSH': {'label': '/', 'title': ''},
    'KC_SPC': {'label': '&#9251;', 'title': 'Space'},
    'KC_SPACE': {'label': '&#9251;', 'title': 'Space'},
    'KC_ESC': {'label': '&#9099;', 'title': 'Escape'},
    'KC_ESCAPE': {'label': '&#9099;', 'title': 'Escape'},
    'KC_PGUP': {'label': '&#8670;', 'title': 'Page Up'},
    'KC_UP': {'label': '&#9650;', 'title': 'Up'},
    'KC_BSPC': {'label': '&#9003;', 'title': 'Backspace'},
    'KC_TAB': {'label': '&#8677;', 'title': 'Tab'},
    'KC_PGDN': {'label': '&#8671;', 'title': 'Page Down'},
    'KC_LEFT': {'label': '&#9668;', 'title': 'Left'},
    'KC_DOWN': {'label': '&#9660;', 'title': 'Down'},
    'KC_RGHT': {'label': '&#9654;', 'title': 'Right'},
    'KC_RIGHT': {'label': '&#9654;', 'title': 'Right'},
    'KC_ENT': {'label': '&#9166;', 'title': 'Enter'},
    'KC_ENTER': {'label': '&#9166;', 'title': 'Enter'},
    'KC_SCLN': {'label': ';', 'title': ''},
    'KC_LPRN': {'label': '(', 'title': ''},
    'KC_RPRN': {'label': ')', 'title': ''},
    'KC_BSLS': {'label': '\\', 'title': ''},
    'KC_MINS': {'label': '-', 'title': ''},
    'KC_ASTR': {'label': '*', 'title': ''},
    'KC_EQL': {'label': '=', 'title': ''},
    'KC_EXLM': {'label': '&#33;', 'title': ''},
    'KC_AT': {'label': '&#64;', 'title': ''},
    'KC_HASH': {'label': '&#35;', 'title': ''},
    'KC_DLR': {'label': '&#36;', 'title': ''},
    'KC_PERC': {'label': '&#37;', 'title': ''},
    'KC_PIPE': {'label': '&#124;', 'title': ''},
    'KC_COLN': {'label': '&#58;', 'title': ''},
    'KC_TILD': {'label': '&#126;', 'title': ''},
    'KC_LT': {'label': '&#60;', 'title': ''},
    'KC_GT': {'label': '&#62;', 'title': ''},
    'GBPD': {'label': '&#163;', 'title': ''},
    'KC_AMPR': {'label': '&#38;', 'title': ''},
    'KC_UNDS': {'label': '&#95;', 'title': ''},
    'PMIN': {'label': '&#177;', 'title': ''},
    'KC_CIRC': {'label': '&#94;', 'title': ''},
    'KC_PLUS': {'label': '&#43;', 'title': ''},
    'KC_LBRACKET': {'label': '[', 'title': ''},
    'KC_RBRACKET': {'label': ']', 'title': ''},
    'KC_GRV': {'label': '`', 'title': ''},
    '_______': {'label': '', 'title': ''},
    'XXXXXXX': {'label': '&#10060;', 'title': ''},
    'KC_CAPS_LOCK': {'label': '&#8682;', 'title': ''},
    'KC_CAPS': {'label': '&#8682;', 'title': ''},
}

# Keycodes with annotations
annotation_keycodes = {
    'mo': {
        'class': 'mo',
        'label': 'MO',
    },
    'tg': {
        'class': '',
        'label': 'TG',
    },
    'osm': {
        'class': '',
        'label': 'osm',
    },
    'lsft': {
        'class': '',
        'label': '&#8679;',
    },
    'lsft_t': {
        'class': '',
        'label': 'MT &#8679;',
    },
    'lctl_t': {
        'class': '',
        'label': 'MT ^',
    },
    'lalt_t': {
        'class': '',
        'label': 'MT &#8997;',
    },
    'lgui_t': {
        'class': '',
        'label': 'MT &#8984;',
    },
    'lcmd': {
        'class': '',
        'label': '&#8984;',
    },
    'df': {
        'class': '',
        'label': 'default',
    },
    'held_css_class': {
        'keycodes': [], # Special case, to provide label for held layer keys
        'label': 'held',
    },
}

_modifier_regex = re.compile(
    '(DF|TG|MO|OSM|LCMD|LSFT|LALT|LCTL|RCMD|RSFT|RALT|RCTL)\(([0-9a-zA-Z_| ]+)\)'
)


class Svg:
    """."""

    def __init__(self):
        _styles = []
        _classes = set()

    def add_style(self, style):
        self._styles.append(style)

    def add_class(self, name, style):
        if name in self._classes:
            return
        else:
            self._styles.append(style)
            self._classes.add(style)

    def __str__(self):
        return '\n'.join(self._header + self._svg_parts + self._footer)


def parse_keymap(path):
    """Parse a JSON keymap file."""
    with open(path) as fh:
        keymap = json.load(fh)

        return keymap


def parse_json_config(path):
    """Parse a JSON configuration file."""
    with open(path) as fh:
        config = json.load(fh)

        for field in _required_config_fields:
            if field not in config:
                sys.exit('no field')

        if 'split' in config:
            if 'left' not in config['layout'] or 'right' not in config['layout']:
                sys.exit('udjrgoij')

        return config


def parse_key2(key):
    """Parse a key and any modifiers."""
    modifiers, keycodes = [], []
    parentheses_seen, last_idx = False, 0

    for idx, char in enumerate(key):
        if char == '(':
            parentheses_seen = True
            modifiers.append(key[last_idx:idx])
            last_idx = idx + 1
        elif char == ')':
            if not keycodes:
                keycodes.extend([k.strip() for k in key[last_idx:idx].split('|')])

    if not parentheses_seen:
        return modifiers, [key]

    return modifiers, keycodes


def parse_key(key):
    """Parse a key from a keymap."""
    m = _modifier_regex.match(key)

    if m:
        # Return the modifier
        return m.group(1), m.group(2).split('|')

    return None, key


def is_layer_mod(modifier):
    """Return whether a modifier is a layer switch modifier."""
    return modifier in ['tg', 'tt', 'mo', 'df']


_svg_header = Template("""<svg width="${svg_width}" height="${svg_height}" viewBox="0 0 ${svg_width} ${svg_height}" xmlns="http://www.w3.org/2000/svg" class="${svg_classes}">
<style>
    svg {
        font-family: ${font_family}, sans-serif;
        font-size: ${font_size}px;
        text-rendering: optimizeLegibility;
        background-color: white;
    }

    text {
    	text-anchor: middle;
    	dominant-baseline: middle;
    }

    .text-container > div {
        cursor: default;
        box-sizing: border-box;
        background-color: #f0f0f0;
        text-align: center;
        width: ${key_width}px;
        height: ${key_height}px;
        border-radius: ${key_radius}px;
        display: flex;
        flex-direction: column;
		overflow: hidden;
    }

    .text-container > div.trans {
        cursor: default;
        box-sizing: border-box;
        background-color: #c064df;
        text-align: center;
        width: ${key_width}px;
        height: ${key_height}px;
        border-radius: ${key_radius}px;
        display: flex;
        flex-direction: column;
		overflow: hidden;
        border-style: dashed;
    }

    .glyph {
        padding: 1px 2px;
        display: flex;
        justify-content: center;
        align-items: center;
        hyphens: auto;
        -webkit-hyphens: auto;
        -moz-hyphens: auto;
        -ms-hyphens: auto;
		flex: 1 0 auto;
        color: ${key_color};
        background-color: ${key_bg_color};
    }

    .glyph-inner {
        border-radius: 6px;
        background-color: #7b7b7b;
        padding: 10px 20px 10px;
        margin-bottom: 4px;
    }

    .text-container > div:after {
        box-sizing: border-box;
        font-size: 11px;
    	font-weight: bold;
    	font-variant: small-caps;
		position: fixed;
		bottom: 0;
		padding-bottom: 1px;
		width: 100%;
		display: none;
    }

    .text-container > div.${held_css_class} > .glyph {
        background-color: #bbf;
    }

    .rgb .text-container > div.${held_css_class} > .glyph {
        background-color: initial;
        border: 3px solid #00e;
        border-bottom-width: 0;
        border-radius: ${key_radius}px ${key_radius}px 0 0;
    }

    .text-container > div.${blank_css_class} {

    }

    .text-container > div.${transparent_css_class} {

    }

    .layer_title {
		font-size: 17px;
		font-weight: bold;
		fill: #777;
    }

    .layer_bg {
        fill: ${layer_bg_color};
        width: ${layer_bg_width}px;
        height: ${layer_bg_height}px;
    }

    .kc_up, .kc_down, .kc_left, .kc_right,
    .kc_ent, .kc_bspc, .os_caps, .kc_esc,
    .kc_lsft, .nav_spc,
    .kc_exlm, .kc_at, .kc_hash, .kc_dlr, .kc_perc,
    .kc_ampr, .kc_astr, .kc_unds, .kc_mins,
    .kc_pipe, .kc_scln, .kc_eql, .kc_coln, .kc_tild,
    .kc_lt, .kc_gt, .kc_grv, .kc_circ, .kc_plus, .kc_bsls,
    .kc_quot, .kc_dot, .kc_comm, .kc_slsh,
    .os_shft, .os_ctrl, .os_alt, .os_cmd,
    .kc_mac_spotlight, .kc_pgup, .kc_pgdn,
    .kc_mac_undo, .kc_mac_redo, .kc_tab,
    .kc_mac_cut, .kc_spc, .kc_mac_lock_scrn,
    .kc_brightness_up, .kc_brightness_down,
    .kc_volu, .kc_vold, .kc_mute,
    .kc_mply, .kc_mprv, .kc_mnxt {
    	font-size: 18px;
    }

    .kc_bspc {
    	font-size: 22px;
    }

    .os_caps {
    	font-size: 19px;
    	padding-top: 4px !important;
    }

    .kc_mac_spotlight {
    	font-size: 40px;
    }

    .kc_mac_undo {
    	font-size: 34px;
    }

    .kc_mac_redo {
    	font-size: 34px;
    }

    .kc_mac_cut {
    	font-size: 20px;
    }

    .kc_spc {
    	font-size: 24px;
    }

    .kc_mac_lock_scrn {
    	font-size: 22px;
    }

    .kc_brightness_up {
    	font-size: 28px;
    }

    .kc_brightness_down {
    	font-size: 32px;
    }

    .kc_audio_vol_down {
    	font-size: 22px;
    }

    .kc_audio_vol_up {
    	font-size: 22px;
    }

    .kc_audio_mute {
    	font-size: 22px;
    }

    .kc_media_play_pause {
    	font-size: 26px;
    }

    .kc_media_prev_track {
    	font-size: 26px;
    }

    .kc_media_next_track {
    	font-size: 26px;
    }

    .annotation {
        box-sizing: border-box;
        font-size: 11px;
    	font-weight: bold;
    	font-variant: small-caps;
		padding-bottom: 2px;
		width: 100%;
        color: ${annotation_color};
		background-color: ${annotation_bg_color};
    }

    .${held_css_class} .annotation.layer {
        background-color: #00e;
    }
${extra_css}
</style>
""")

_svg_footer = """</svg>"""

_svg_layer_title = Template("""
<text x="${layer_title_x}" y="${layer_title_y}" class="layer_title">${layer_title}</text>
""")

_svg_layer_class = Template(""".${layer_bg_name} {
    fill: ${layer_bg_color};
    width: ${layer_bg_width}px;
    height: ${layer_bg_height}px;
}""")

_svg_layer_bg = Template("""<rect rx="${key_radius}" x="${layer_bg_x}" y="${layer_bg_y}" class="${layer_class}" />""")

_svg_key = Template("""
<foreignObject x="${key_x}" y="${key_y}" width="${key_width}" height="${key_height}" class="text-container">
  <div xmlns="http://www.w3.org/1999/xhtml" lang="en" ${title_attr}class="${key_classes}">
    <div class="glyph">${key_label}</div>${annotation}
  </div>
</foreignObject>
""")

_svg_annotation = Template(""".${name} {
        box-sizing: border-box;
        font-size: 11px;
        font-weight: bold;
        font-variant: small-caps;
        padding-bottom: 2px;
        width: 100%;
        color: #f6f6f6;
        background-color: ${background_color};
    }""")


def generate_key_annotation(key, modifiers, layer_idx, annotations):
    """."""
    annotation = ''
    modifiers = [modifier.lower() for modifier in modifiers]
    valid = modifiers and all([modifier in annotations for modifier in modifiers])

    if valid:
        if modifiers and all(is_layer_mod(modifier) for modifier in modifiers):
            return '<div class="annotation {}">{}</div>'.format(
                f'annotation-mo-{layer_idx}',
                annotations[modifiers[0]]['label'],
            )
        else:
            return '<div class="annotation">{}</div>'.format(
                ''.join([annotations[mod]['label'] for mod in modifiers])
            )

    # for clazz in annotations:
    #     if key in annotations[clazz]['keycodes']:
    #         content = annotations[clazz]['label']

    #         if False:#key_is_held:
    #             content = annotations[held_css_class]['label']

    #         annotation = '<div class="annotation {}">{}</div>'.format(
    #             clazz,
    #             content,
    #         )

    #         break

    return annotation


def get_key_label(name):
    """."""
    if name in key_names:
        return key_names[name]['label']
    else:
        return name[len(keycode_prefix):]\
            if name.startswith(keycode_prefix) else name


def generate_key(
    key,
    x,
    y,
    factor_x,
    factor_y,
    width,
    height,
    radius,
    classes,
    key_names,
    layers,
    x_offset=0,
    y_offset=0,
):
    """Generate the svg for a single key."""
    color, mod = '', ''
    layer_idx = -1
    modifiers, keycodes = parse_key2(key)
    label = ''.join([get_key_label(keycode) for keycode in keycodes])

    # if len(keycodes) > 1:
    #     sys.stderr.write(get_key_label(keycodes[0]) + '\n')
    #     sys.stderr.write(get_key_label(keycodes[1]) + '\n')
    #     sys.stderr.write(label + '\n')

    if modifiers:
        if len(modifiers) == 1 and is_layer_mod(modifiers[0].lower()):
            # Handle layer modifier like MO, TG, etc.
            keycode = keycodes[0]
            layer = layers[keycode]
            color, label, layer_idx = layer['color'], layer['keycode'], layer['idx']
    else:
        # Handle keycodes without modifiers
        pass

    label = get_key_label(label)
    annotation = generate_key_annotation(label, modifiers, layer_idx, annotation_keycodes)
    key_x = x + x_offset + factor_x * width
    key_y = y + y_offset + factor_y * height

    return key_x, key_y, _svg_key.substitute({
        'key_radius': radius,
        'key_x': key_x,
        'key_y': key_y,
        'title_attr': '',
        'key_classes': ' '.join(classes),
        'key_width': width,
        'key_height': height,
        'key_label': label,
        'annotation': annotation,
        'color': color,
    })


def generate_split(
    half,
    layers,
    keymap,
    start_x,
    start_y,
    key_width,
    key_height,
    key_radius,
    key_spacing,
    border,
    key_names,
    x_offset=0,
    y_offset=0,
):
    """Generate a split layer."""
    x, y = start_x + border, start_y + border
    max_x, max_y = x, y
    svg_parts = []

    for row_idx, rows in enumerate(half):
        for idx, row in enumerate(rows):
            key_classes = ['transparent']
            key = keymap[row_idx][idx]
            alt_label = key_names['KC_EXLM']['label']

            key_x, key_y, svg = generate_key(
                key,
                x,
                y,
                row['dx'],
                row['dy'],
                key_width,
                key_height,
                key_radius,
                key_classes,
                key_names,
                layers,
                x_offset,
                y_offset,
            )

            svg_parts.append(svg)

            x += key_spacing
            max_x = max([max_x, key_x + key_width])
            max_y = max([max_y, key_y + key_height])

        y += key_spacing
        x = start_x + border

    return max_x, max_y, svg_parts


def generate_layer(layer, layer_idx, layers, position, config, options):
    """Generate the svg for a single layer."""
    svg_parts = []
    x, y = position

    if layer['label']:
        layer_title_y = y + layer_title_height / 2.0
        y += (layer_title_height + layer_title_spacing)

    # Add background
    svg_parts.append(
        _svg_layer_bg.substitute({
            'key_radius': options['key_radius'],
            'layer_bg_x': x,
            'layer_bg_y': y,
            'layer_class': f'layer_{layer_idx}'
        })
    )

    max_x_left = x

    # Generate left half
    max_x_left, max_y, left_svg = generate_split(
        config['layout']['left'],
        layers,
        layer['left'],
        x + options['border_spacing'],
        y + options['border_spacing'],
        options['key_width'],
        options['key_height'],
        options['key_radius'],
        options['key_spacing'],
        options['border_spacing'],
        key_names
    )

    svg_parts.extend(left_svg)
    y = position[1] + options['border_spacing']
    max_x_right = max_x_left

    if layer['label']:
        layer_title_y = y + layer_title_height / 2.0
        y += (layer_title_height + layer_title_spacing)

    # Generate right half
    max_x_left, max_y, right_svg = generate_split(
        config['layout']['right'],
        layers,
        layer['right'],
        x + options['border_spacing'],
        y + options['border_spacing'],
        options['key_width'],
        options['key_height'],
        options['key_radius'],
        options['key_spacing'],
        options['border_spacing'],
        key_names,
        x_offset=max_x_left + options['split_spacing']
    )

    svg_parts.extend(right_svg)

    lol = (max_x_left - position[0] - options['border_spacing']) / 2 + position[0] + options['border_spacing']

    svg_parts.append(
        _svg_layer_title.substitute({
            'layer_title_x': lol,#position[0] / 2 + options['border_spacing'] + max_x_left / 2,
            'layer_title_y': layer_title_y,
            'layer_title': layer['label'],
        })
    )

    # Add a new class for this layer
    svg_header_parts = [
        _svg_layer_class.substitute({
            'layer_bg_name': f'layer_{layer_idx}',
            'layer_bg_color': layer['color'] if 'color' in layer else '#c0c0c0',
            'layer_bg_width': max_x_left - position[0] +
            options['border_spacing'] * 2,
            'layer_bg_height': max_y - position[1] + options['border_spacing'] * 2,
        })
    ]

    return max_x_left, max_y, svg_header_parts, svg_parts


def commalist(value):
    """Split a comma-separated string into a list."""
    return [elem.strip() for elem in value.split(',')]


def parse_command_line():
    """Parse command line arguments."""
    parser = argparse.ArgumentParser(description='')

    parser.add_argument(
        '-x', type=int, default=0, help='X position of layout'
    )
    parser.add_argument(
        '-y', type=int, default=0, help='Y position of layout'
    )
    parser.add_argument(
        '-n',
        '--no-layer-titles',
        action='store_true',
        help='Do not render layer titles',
    )
    parser.add_argument(
        '-t',
        '--show-transparent-keycodes',
        action='store_true',
        help='Show the key for the underlying layer for transparent keys'
    )
    parser.add_argument(
        '-d', '--debug', action='store_true', help='Print debug information'
    )
    parser.add_argument(
        '-s',
        '--key-spacing',
        default=4,
        type=int,
        help='Spacing between each key',
    )
    parser.add_argument(
        '--key-color', type=str, default='black', help='The color of keys'
    )
    parser.add_argument(
        '--key-bg-color',
        type=str,
        default='white',
        help='The background color of keys',
    )
    parser.add_argument(
        '--key-width', type=int, default=65, help='The width of each key'
    )
    parser.add_argument(
        '--key-height', type=int, default=55, help='The height of each key'
    )
    parser.add_argument(
        '-r',
        '--key-radius',
        type=int,
        default=6,
        help='The radius (rounded borders) of each key'
    )
    parser.add_argument(
        '--border-spacing',
        type=int,
        default=0,
        help='The border spacing around the keys in each layer'
    )
    parser.add_argument(
        '-b', '--keyboard', type=str, help='The keyboard layout'
    )
    parser.add_argument(
        '-m', '--keymap', type=str, help='The keymap'
    )
    parser.add_argument(
        '-c', '--config', type=str, help='Pre-defined config with options'
    )
    parser.add_argument(
        '--layer-bg-color',
        type=str,
        default='#c0c0c0',
        help='The global background color for layers. Overwrites specific layer'
             'colors.'
    )
    parser.add_argument(
        '--layer-spacing',
        type=int,
        default=100,
        help='The spacing between each layer'
    )
    parser.add_argument(
        '--split-spacing',
        type=int,
        default=100,
        help='The spacing between each half of a split keyboard',
    )
    parser.add_argument(
        '--font-size',
        type=int,
        default=14,
        help='The global font size'
    )
    parser.add_argument(
        '--font-family',
        type=commalist,
        default='-apple-system, "Helvetica Neue"',
        help='The global font family'
    )
    parser.add_argument(
        '--annotation-color',
        type=str,
        default='#f6f6f6',
        help='The default color for key annotations'
    )
    parser.add_argument(
        '--annotation-bg-color',
        type=str,
        default='#666',
        help='The default background color for key annotations'
    )

    return parser.parse_args()


if __name__ == '__main__':
    layer_title_height = 20
    layer_title_spacing = 10

    args = parse_command_line()

    config = parse_json_config('./ferris-sweep-config-factors.json')
    keymap = parse_keymap('./ferris-sweep-keymap.json')

    if args.debug:
        print(json.dumps(config, indent=2))

    svg_parts = []
    svg_header_parts = []
    svg_layers = []
    svg_layer_classes = []
    layer_options = {
        'key_radius': args.key_radius,
        'key_width': args.key_width,
        'key_height': args.key_height,
        'key_spacing': args.key_spacing,
        'split_spacing': args.split_spacing,
        'border_spacing': args.border_spacing,
    }

    x, y = args.x, args.y

    key_names = { **key_names, **keymap['extra_keymappings'] }

    for layer_idx, layer_name in enumerate(keymap['layers']):
        layer = keymap['layers'][layer_name]
        layer['idx'] = layer_idx

        svg_header_parts.append(
            _svg_annotation.substitute({
                'name': f'annotation-mo-{layer_idx}',
                'background_color': layer['color'] if 'color' in layer else '#666',
            })
        )

    for layer_idx, layer_name in enumerate(keymap['layers']):
        layer = keymap['layers'][layer_name]

        max_x, max_y, layer_class, layer_svg = generate_layer(
            layer,
            layer_idx,
            keymap['layers'],
            (x, y),
            config,
            layer_options
        )

        y += 500
        svg_layers.extend(layer_svg)
        svg_layer_classes.extend(layer_class)

    svg_parts.append(
        _svg_header.substitute({
            'svg_width': args.border_spacing * 2 + max_x,
            'svg_height': args.border_spacing * 2 + max_y,
            'key_color': args.key_color,
            'key_bg_color': args.key_bg_color,
            'key_radius': args.key_radius,
            'key_width': args.key_width,
            'key_height': args.key_height,
            'svg_classes': [],
            'held_css_class': 'held',
            'blank_css_class': 'blank',
            'transparent_css_class': 'transparent',
            'layer_bg_color': args.layer_bg_color,
            'layer_bg_width': max_x - args.x + args.border_spacing * 2,
            'layer_bg_height': max_y - args.y + args.border_spacing * 2,
            'extra_css': '\n'.join(svg_layer_classes + svg_header_parts),
            'font_size': args.font_size,
            'font_family': ', '.join(args.font_family),
            'annotation_color': args.annotation_color,
            'annotation_bg_color': args.annotation_bg_color,
        })
    )

    svg_parts.extend(svg_layers)
    svg_parts.append(_svg_footer)

    print('\n'.join(svg_parts))
